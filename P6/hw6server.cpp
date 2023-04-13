#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <string>
#include <iostream>
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <jsonrpccpp/client/connectors/httpclient.h>

#include "hw6server.h"
#include "hw6client.h"

#include "ecs36b_Common.h"
#include "JvTime.h"
#include <string.h>
#include <strings.h>

using namespace jsonrpc;
using namespace std;

#define WORD_LENGTH 5
#define ALPHA_SIZE 27
FILE *fpAll,  *fpSol;

long wordCount = 0;
char word[WORD_LENGTH + 1] = {0};
char alpha[ALPHA_SIZE] = "abcdefghijklmnopqrstuvwxyz";

// from wordle.c, except the memcache stuff is removed
// credit -- https://github.com/AyrA/Wordle-C
// wordle C is a program developed by Ayra (a big THANKS!!)



#define _WORDLE_C_
#ifdef  _WORDLE_C_

int pickWord(char * word, int index);
bool hasWord(const char * word);
int toLower(char * str);
bool checkWord(const char * guess);
bool isWord(const char* word);
int strpos(const char * str, char search);

char check_result[WORD_LENGTH + 1];

bool
checkWord
(const char *arg_guess)
{
  if (strlen(arg_guess) == strlen(word))
    {
      int i = 0;
      int pos = -1;
      //Copy is used to blank found characters
      //This avoids wrong reports for double letters, for example "l" in "balls"
      char lv_copy[WORD_LENGTH + 1];
      char lv_result[WORD_LENGTH + 1];
      lv_result[WORD_LENGTH] = 0;
      strcpy(lv_copy, word);
      //Do all correct positions first
      while (lv_copy[i]) {
	  if (lv_copy[i] == arg_guess[i])
	    {
	      //Character found and position correct
	      lv_result[i] = '#';
	      lv_copy[i] = '_';
	    }
	  else
	    {
	      //Fills remaining slots with blanks
	      //We could do this before the loop as well
	      lv_result[i] = '_';
	    }
	  i++;
	}
      i = 0; //reset i before next loop

      while (lv_copy[i])
	{
	  pos = strpos(lv_copy, arg_guess[i]);
	  //Char must exist but do not overwrite a good guess
	  if (pos >= 0 && lv_result[i] != '#')
	    {
	      //Character found but position wrong
	      lv_result[i] = 'o';
	      lv_copy[pos] = '_';
	    }
	  ++i;
	}
      snprintf(check_result, WORD_LENGTH + 1, "%s", lv_result);
      return true;
    }

  return false;
}

int
toLower(char *str)
{
  int i = 0;
  while (str[i]) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      {
	str[i] |= 0x20; //Make lowercase
      }
    ++i;
  }
  return i;
}

int
strpos
(const char * str, char search)
{
  int i = 0;
  if (str != NULL)
    {
      while (str[i])
	{
	  if (str[i] == search)
	    {
	      return i;
	    }
	  ++i;
	}
    }
  return -1;
}

bool
isWord(const char* arg_word)
{
  int i = -1;
  // std::cout << "isWord = " << arg_word << std::endl;

  if(strlen(arg_word) == WORD_LENGTH)
    {
      while(arg_word[++i])
	{
	  if(arg_word[i]<'a' || arg_word[i]>'z')
	    {
	      return false;
	    }
	}
      return true;
    }
  return false;
}

bool
hasWord
(const char * arg_word)
{
  //A bit longer to also contain the line terminator
  char buffer[WORD_LENGTH + 4];

  // std::cout << "hasWord = " << arg_word << std::endl;

  //Don't bother if the argument is invalid
  if (arg_word == NULL || strlen(arg_word) != WORD_LENGTH || !isWord(arg_word))
    {
      return false;
    }

  fseek(fpAll, 0, SEEK_SET);
  //Stop comparing once we are beyond the current letter
  while (fgets(buffer, WORD_LENGTH + 4, fpAll) != NULL)
    {
      buffer[WORD_LENGTH]=0;
      // std::cout << "buffer = " << buffer << std::endl;

      if (strcmp(arg_word, buffer) == 0)
	{
	  return true;
	}
    }
  return false;
}

int
pickWord
(char * word, int index)
{
  int i = 0;
  fseek(fpSol, 0, SEEK_SET);
  while (i <= index && fgets(word, WORD_LENGTH + 1, fpSol) != NULL)
    {
      if (strlen(word) == WORD_LENGTH)
	{
	  ++i;
	}
    }
  return index;
}

#endif  /* _WORDLE_C_ */

class Myhw6Server : public hw6Server
{
public:
  Myhw6Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value set_name(const std::string& action, const Json::Value& student_list, const std::string& team_name);
  virtual Json::Value obtain(const std::string& action, const std::string& class_id, const std::string& game_id);
  virtual Json::Value guess(const std::string& action, const std::string& class_id, const std::string& game_id, const std::string& my_guess);
  virtual Json::Value submit(const std::string& action, const std::string& game_id, const std::string& team_name);
};

Myhw6Server::Myhw6Server(AbstractServerConnector &connector, serverVersion_t type)
  : hw6Server(connector, type)
{
  std::cout << "Myhw6Server Object created" << std::endl;
}

//Code is being edited from here onwards



Json::Value
Myhw6Server::set_name

/*
virtual Json::Value set_name(const std::string& action, const Json::Value& student_list, const std::string& team_name);
  virtual Json::Value obtain(const std::string& action, const std::string& class_id, const std::string& game_id);
  virtual Json::Value guess(const std::string& action, const std::string& class_id, const std::string& game_id, const std::string& my_guess);
  virtual Json::Value submit(const std::string& action, const std::string& game_id, const std::string& team_name);*/
(const std::string& action, const Json::Value& student_list,
 const std::string& team_name)
{

  Json::Value lv_log;
  lv_log["arg action"] = action;
  lv_log["arg student_list"] = student_list;
  lv_log["arg team_name"] = team_name;

  int i;
  int error_code = 0;
  int rc = 0;
  Json::Value result;

  char buf_fname1[256];
  bzero(buf_fname1, 256);
  snprintf(buf_fname1, 255, "./config/ecs36b_teams.json");

  char buf_fname2[256];
  bzero(buf_fname2, 256);
  snprintf(buf_fname2, 255, "./config/ecs36b_students.json");

  Json::Value lv_teams;
  Json::Value lv_students;

  try {
    rc = myFile2JSON(buf_fname1, &lv_teams);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception
	  { ("myFile2JSON error " + std::string { buf_fname1 }) };
      }

    if((lv_teams.isNull() == false) &&
       (lv_teams.isObject() == false))
      {
	error_code = -1;
	throw ecs36b_Exception
	  { ("teams JSON format incorrect " + std::string { buf_fname1 }) };
      }

    rc = myFile2JSON(buf_fname2, &lv_students);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception
	  { ("myFile2JSON error " + std::string { buf_fname2 }) };
      }

    if ((lv_students.isNull() == true) ||
	(lv_students.isObject() == false))
      {
	error_code = -2;
	throw ecs36b_Exception
	  { ("students JSON format incorrect " + std::string { buf_fname2 }) };
      }

    if (team_name.empty())
      {
	error_code = -3;
	throw ecs36b_Exception { ("team name empty") };
      }

    if ((student_list.isNull() == true) ||
	(student_list.isArray() == false) ||
	(student_list.size() == 0))
      {
	error_code = -4;
	throw ecs36b_Exception {("student list JSON array format incorrect")};
      }

    if ((lv_teams[team_name]).isNull() == false)
      {
	error_code = -5;
	throw ecs36b_Exception
	  { ("team name already taken: " + team_name) };
      }

    // set up a new team
    // check if the team members have been registered with other team
    Json::Value lv_jv;
    for (i = 0; i < student_list.size(); i++)
      {
	if ((student_list[i]).isString() == false)
	  {
	    error_code = -6;
	    throw ecs36b_Exception
	      { ("student name is not a string. index = " + std::to_string(i)) };
	  }
	else
	  {
	    lv_jv = lv_students[(student_list[i]).asString()];
	    if ((lv_jv.isNull() == true) ||
		(lv_jv.isObject() == false))
	      {
		error_code = -7;
		throw ecs36b_Exception
		  { ("student format incorrect. index = " + std::to_string(i)) };
	      }

	    if ((lv_jv["team name"].isNull() == true) ||
		(lv_jv["team name"].isString() == false) ||
		(lv_jv["team name"]).asString() != "unassigned")
	      {
		error_code = -8;
		throw ecs36b_Exception
		  { ("team_name not unassigned. index = " + std::to_string(i)) };
	      }
	  }
      }

    for (i = 0; i < student_list.size(); i++)
      {
	lv_students[(student_list[i]).asString()]["team name"]
	  = team_name;
	lv_students[(student_list[i]).asString()]["score"]
	  = 0;
      }
    lv_teams[team_name] = student_list;

    // save to both files
    rc = myJSON2File(buf_fname1, &lv_teams);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception
	  { ("myJSON2File error " + std::string { buf_fname1 }) };
      }

    rc = myJSON2File(buf_fname2, &lv_students);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception
	  { ("myJSON2File error " + std::string { buf_fname2 }) };
      }
  } catch (ecs36b_Exception& e) {
    std::cerr << e.what() << std::endl;
    result["reason"] = e.what();
    result["error_code"] = error_code;
    result["status"] = "failed";
  }

  result["word"] = "?????";
  lv_log["result"] = result;
  myPrintLog(lv_log.toStyledString(), "./config/hw6server.log");

  return result;
}

Json::Value
Myhw6Server::submit
(const std::string& action, const std::string& game_id,
 const std::string& team_name)
{
  Json::Value lv_log;
  lv_log["arg action"] = action;
  lv_log["arg game_id"] = game_id;
  lv_log["arg team_name"] = team_name;

  int i;
  int error_code = 0;
  int rc = 0;
  Json::Value result;

  try {
    if (game_id.empty())
      {
	error_code = -2;
	throw ecs36b_Exception { "game_id null" };
      }

    char buf_fname[256];
    char buf_gid[256];

    bzero(buf_fname, 256);
    snprintf(buf_fname, 255, "./games/wordle_%s.json", game_id.c_str());
    rc = myFile2JSON(buf_fname, &result);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception { "myFile2JSON error" };
      }

    if((result["check_word"].isNull() == true) ||
       (result["check_word"].isString() == false) ||
       (result["check_word"].asString() != "#####"))
      {
	error_code = -3;
	throw ecs36b_Exception { "check_word is ill-formated or incomplete" };
      }

    if ((result["remaining_score"].isNull() == true) ||
	(result["remaining_score"].isInt() == false) ||
	(result["remaining_score"].asInt() <= 0))
      {
	error_code = -4;
	throw ecs36b_Exception { "remaining score has reached zero" };
      }

    if ((result["score_distributed"].isNull() == true) ||
	(result["score_distributed"].isBool() == false) ||
	(result["score_distributed"].asBool() == true))
      {
	error_code = -5;
	throw ecs36b_Exception { "score has been distributed" };
      }

    char buf_fname1[256];
    bzero(buf_fname1, 256);
    snprintf(buf_fname1, 255, "./config/ecs36b_teams.json");

    char buf_fname2[256];
    bzero(buf_fname2, 256);
    snprintf(buf_fname2, 255, "./config/ecs36b_students.json");

    Json::Value lv_teams;
    Json::Value lv_students;

    rc = myFile2JSON(buf_fname1, &lv_teams);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception
	  { ("myFile2JSON error " + std::string { buf_fname1 }) };
      }

    if((lv_teams.isNull() == false) &&
       (lv_teams.isObject() == false))
      {
	error_code = -1;
	throw ecs36b_Exception
	  { ("teams JSON format incorrect " + std::string { buf_fname1 }) };
      }

    rc = myFile2JSON(buf_fname2, &lv_students);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception
	  { ("myFile2JSON error " + std::string { buf_fname2 }) };
      }

    if ((lv_students.isNull() == true) ||
	(lv_students.isObject() == false))
      {
	error_code = -2;
	throw ecs36b_Exception
	  { ("students JSON format incorrect " + std::string { buf_fname2 }) };
      }

    if (team_name.empty())
      {
	error_code = -3;
	throw ecs36b_Exception { ("team name empty") };
      }

    Json::Value lv_team_list = lv_teams[team_name];
    if ((lv_team_list.isNull() == false) &&
	(lv_team_list.isArray() == true))
      {
	Json::Value lv_score_list;
	for (i = 0; i < lv_team_list.size(); i++)
	  {
	    std::string lv_student_id = (lv_team_list[i]).asString();
	    int lv_score = lv_students[lv_student_id]["score"].asInt();
	    lv_score += result["remaining_score"].asInt();
	    lv_students[lv_student_id]["score"] = lv_score;
	    // send the scores back
	    lv_score_list[i] = lv_score;
	  }
	result["score_distributed"] = true;

	// save to all three files
	rc = myJSON2File(buf_fname1, &lv_teams);
	if (rc != 0)
	  {
	    error_code = rc;
	    throw ecs36b_Exception
	      { ("myJSON2File error " + std::string { buf_fname1 }) };
	  }

	rc = myJSON2File(buf_fname2, &lv_students);
	if (rc != 0)
	  {
	    error_code = rc;
	    throw ecs36b_Exception
	      { ("myJSON2File error " + std::string { buf_fname2 }) };
	  }

	rc  = myJSON2File(buf_fname, &result);
	if (rc != 0)
	  {
	    error_code = rc;
	    throw ecs36b_Exception
	      { ("myJSON2File error " + std::string { buf_fname }) };
	  }

	error_code = 0;
	result["scores"] = lv_score_list;
	result["status"] = "successful";
      }
  } catch (ecs36b_Exception& e) {
    std::cerr << e.what() << std::endl;
    result["reason"] = e.what();
    result["error_code"] = error_code;
    result["status"] = "failed";
  }

  result["word"] = "?????";

  lv_log["result"] = result;
  myPrintLog(lv_log.toStyledString(), "./config/hw6server.log");

  return result;
}

Json::Value
Myhw6Server::obtain
(const std::string& action, const std::string& class_id,
 const std::string& game_id)
{
  Json::Value lv_log;
  lv_log["arg action"] = action;
  lv_log["arg class_id"] = class_id;
  lv_log["arg game_id"] = game_id;

  int rc = 0;
  int error_code = 0;
  Json::Value result;

  try {
    if (class_id != "Wordle")
      {
	error_code = -1;
	throw ecs36b_Exception { ("class " + class_id + " unknown") };
      }

  if (game_id.empty())
    {
      error_code = -2;
      throw ecs36b_Exception { "game_id null" };
    }

  char buf_fname[256];
  char buf_gid[256];
  FILE *target;

  if (game_id == "00000000")
    {
      // new game
      unsigned int my_rand = rand();
      my_rand = my_rand % 100000;

      JvTime * my_now_ptr = getNowJvTime();
      std::string *my_now_str = my_now_ptr->getTimeString();

      bzero(buf_gid, 256);
      snprintf(buf_gid, 255, "%d_%s",
	       my_rand, my_now_str->c_str());

      bzero(buf_fname, 256);
      snprintf(buf_fname, 255, "./games/wordle_%s.json",
	       buf_gid);
      target = fopen(buf_fname, "a");
      if (target == NULL)
	{
	  error_code = -4;
	  throw ecs36b_Exception { "cannot open the target Wordle game!" };
	}
      fclose(target);

      result["game_id"] = buf_gid;
      result["remaining_score"] = 100;
      result["score_distributed"] = false;

      // try to find the solution word
      my_rand = rand();
      my_rand = my_rand % 2314;

      int pi = pickWord(word, my_rand);
      if (pi != my_rand)
	{
	  error_code = -5;
	  throw ecs36b_Exception { "pickWord mismatching error" };
	}
      result["word"] = word;
      result["check_word"] = "_____";

      rc = myJSON2File(buf_fname, &result);
      if (rc == 0)
	{
	  result["status"] = "successful";
	}
      else
	{
	  error_code = rc;
	  throw ecs36b_Exception { "myJSON2File error" };
	}
    }
  else
    {
      // trying to retrieve an existing game
      bzero(buf_fname, 256);
      snprintf(buf_fname, 255, "./games/wordle_%s.json", game_id.c_str());
      rc = myFile2JSON(buf_fname, &result);
      if (rc == 0)
	{
	  result["status"] = "successful";
	}
      else
	{
	  error_code = rc;
	  throw ecs36b_Exception { "myJSON2File error" };
	}
    }
  } catch (ecs36b_Exception& e) {
    std::cerr << e.what() << std::endl;
    result["reason"] = e.what();
    result["error_code"] = error_code;
    result["status"] = "failed";
  }

  // remember to mask the real solution before returning
  result["word"] = "?????";

  lv_log["result"] = result;
  myPrintLog(lv_log.toStyledString(), "./config/hw6server.log");

  return result;
}

Json::Value
Myhw6Server::guess
(const std::string& action, const std::string& class_id,
 const std::string& game_id, const std::string& my_guess)
{
  Json::Value lv_log;
  lv_log["arg action"] = action;
  lv_log["arg class_id"] = class_id;
  lv_log["arg game_id"] = game_id;
  lv_log["arg my_guess"] = my_guess;

  int rc;
  int error_code = 0;
  Json::Value result;

  try {
    if (class_id != "Wordle")
      {
	error_code = -1;
	throw ecs36b_Exception { ("class " + class_id + " unknown") };
      }

    if (game_id.empty())
      {
	error_code = -2;
	throw ecs36b_Exception { "game_id null" };
      }

    char buf_fname[256];
    char buf_gid[256];
    FILE *target;

    bzero(buf_fname, 256);
    snprintf(buf_fname, 255, "./games/wordle_%s.json", game_id.c_str());
    rc = myFile2JSON(buf_fname, &result);
    if (rc != 0)
      {
	error_code = rc;
	throw ecs36b_Exception { "myFile2JSON error" };
      }

    if ((result["check_word"].isNull() == true) ||
	(result["check_word"].isString() == false))
      {
	error_code = -3;
	throw ecs36b_Exception { "check_word invalid in the file" };
      }

    if (result["check_word"].asString() == "#####")
      {
	error_code = -4;
	throw ecs36b_Exception { "Wordle solved already" };
      }

    if((result["word"].isNull() == true) ||
       (result["word"].isString() == false) ||
       ((result["word"].asString()).size() != 5))
      {
	error_code = -5;
	throw ecs36b_Exception { "solution word invalid in the file" };
      }

    bzero(word, WORD_LENGTH + 1);
    snprintf(word, WORD_LENGTH + 1, "%s", (result["word"].asString()).c_str());
    toLower(word);

    char lv_guess[WORD_LENGTH + 1];
    bzero(lv_guess, WORD_LENGTH + 1);
    snprintf(lv_guess, WORD_LENGTH + 1, "%s", my_guess.c_str());
    toLower(lv_guess);

    if (strcmp(lv_guess, word) == 0)
      {
	// guessed right




	result["check_word"] = "#####";
	int index = (result["guesses"]["data"]).size();
	Json::Value lv_jv;
	lv_jv["guess"] = lv_guess;
	lv_jv["result"] = "#####";
	JvTime * my_now_ptr = getNowJvTime();
	std::string *my_now_str = my_now_ptr->getTimeString();
	lv_jv["time"] = (*my_now_str);
	result["guesses"]["data"][index] = lv_jv;

	rc = myJSON2File(buf_fname, &result);
	if (rc == 0)
	  {
	    result["status"] = "successful";
	  }
	else
	  {
	    error_code = rc;
	    throw ecs36b_Exception { "myJSON2File error" };
	  }
      }
    else
      {
	if (isWord(lv_guess) && hasWord(lv_guess))
	  {
	    if (checkWord(lv_guess))
	      {
		std::cout << "checkWord done \n";

		result["check_word"] = check_result;
		int index = (result["guesses"]["data"]).size();
		Json::Value lv_jv;
		lv_jv["guess"] = lv_guess;
		lv_jv["result"] = check_result;
		JvTime * my_now_ptr = getNowJvTime();
		std::string *my_now_str = my_now_ptr->getTimeString();
		lv_jv["time"] = (*my_now_str);
		result["guesses"]["data"][index] = lv_jv;
		if((result["remaining_score"].isNull() == false) &&
		   (result["remaining_score"].isInt() == true))
		  {
		    int lv_remaining = result["remaining_score"].asInt();
		    result["remaining_score"] = lv_remaining -1;
		  }
		rc = myJSON2File(buf_fname, &result);
		if (rc == 0)
		  {
		    result["status"] = "successful";
		  }
		else
		  {
		    error_code = rc;
		    throw ecs36b_Exception { "myJSON2File error" };
		  }
	      }
	    else
	      {
		result["check_word"] = "_____";
		error_code = -7;
		throw ecs36b_Exception { "checkWord false strlen mismatched" };
	      }
	  }
	else
	  {
	    result["check_word"] = "_____";
	    error_code = -8;
	    throw ecs36b_Exception { "Guess word not in the list" };
	  }
      }
  } catch(ecs36b_Exception& e) {
    std::cerr << e.what() << std::endl;
    result["reason"] = e.what();
    result["error_code"] = error_code;
    result["status"] = "failed";
  }

  result["word"] = "?????";

  lv_log["result"] = result;
  myPrintLog(lv_log.toStyledString(), "./config/hw6server.log");

  return result;
}

int
main(void)
{
  JvTime * my_ptr = getNowJvTime();
  fpAll = fopen("./lists/ALL.TXT", "r");
  fpSol = fopen("./lists/SOLUTION.TXT", "r");
  if (fpAll == NULL || fpSol == NULL)
    {
      std::cout << "error opening wordle lists\n";
      exit(-2);
    }

  srand((my_ptr->second) * (my_ptr->minute) * (my_ptr->year));
  HttpServer httpserver(8384);
  Myhw6Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  std::cout << "Hit enter to stop the server" << endl;
  getchar();

  s.StopListening();
  return 0;
}
