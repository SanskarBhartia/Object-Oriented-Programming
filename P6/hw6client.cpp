
// ecs36b first program
#include <iostream>
#include "ecs36b_Exception.h"
#include <string.h>
#include <strings.h>
#include <time.h>

// JSON RPC part
#include "hw6client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

//Files for lists that contain all words and solutions
FILE *fpAll,  *fpSol;

//Function Prototypes
int pickWord(char * word, int index);

int main()
{
  // distributed wordle demo for 11/23/2022
  // HttpClient httpclient("http://127.0.0.1:8384");

  //comment out either 28 or 29 depending on if the server is up
  HttpClient httpclient("https://ce56646b42df.ngrok.io");
  //HttpClient httpclient("http://localhost:8384");

  hw6Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value jv_list;

  jv_list[0] = "918323992";
  jv_list[1] = "919252622";
  jv_list[2] = "919640810";


  //Sets name for our team
  try {
    myv = myClient.set_name("set_name", jv_list, "TeamSAM");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  //Obtains a Game ID
  try {
    myv = myClient.obtain("obtain", "Wordle", "00000000");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }





  string solution = "#####";
  char guess[5] = {0};

  int i = 0;


  fpSol = fopen("./lists/SOLUTION.TXT", "r");


  if (fpSol == NULL) {
		cout << "error opening wordle lists" << endl;
    }

  srand(time(0));
  while (myv["check_word"]!=solution && i < 100)
  {
    pickWord(guess,(rand()%2315));


    try {
    myv = myClient.guess("guess", "Wordle",myv["game_id"].asString(),guess);
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }

    i++;
  }

  try {
    myv = myClient.submit("submit",myv["game_id"].asString(), "TeamSAM");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }

  std::cout << myv.toStyledString() << std::endl; //outputs JSON data from the game

  return 0;
}

//function that picks a word from the solution list, given an index
int pickWord(char * word, int index) {
	int i = 0;
	fseek(fpSol, 0, SEEK_SET);
	while (i <= index && fgets(word, 5 + 1, fpSol) != NULL) {
		if (strlen(word) == 5) {
			++i;
		}
	}
	return index;
}solution
