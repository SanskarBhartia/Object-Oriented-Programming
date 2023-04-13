
#ifndef _COMMONFILES_H_
#define _COMMONFILES_H_

// ecs36b_Common.h

#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// for Json::value

//#include <jsoncpp/json/json.h>
//#include <jsoncpp/json/reader.h>
//#include <jsoncpp/json/writer.h>
//#include <jsoncpp/json/value.h>

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>




// c library
#include <arpa/inet.h>

using namespace std;


// utility functions
void myPrintLog(std::string content, std::string fname);
int myParseJSON(std::string input, Json::Value * jv_ptr);
char *myFile2String(char *f_name);
int myFile2JSON(char *f_name, Json::Value * jv_ptr);
int myJSON2File(char *f_name, Json::Value * jv_ptr);

#endif /* _ECS36B_COMMONy_H_ */
