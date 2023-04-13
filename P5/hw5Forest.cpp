#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include "Person.h"
#include "Thing.h"
#include <time.h>
#include "hw5Server.cpp"
#include "hw5client.h"

using namespace jsonrpc;
using namespace std;

int main() {

  // std::cout << "Forest" << std::endl;

  HttpClient httpclient("http://127.0.0.1:7376");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value GPS;
  GPS["location"] = "Grandma's Home";

  HttpServer httpserver(7375);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)

  while(s.complete == false) {
      s.StartListening();
      //std::cout << "Hit enter to stop the server" << endl;
  }
  s.StopListening();
 
   std::cout << "The Object Are Leaving the Forest" << std::endl;

// Access every value in person
  for (auto it = s.Person_Map.begin(); it != s.Person_Map.end(); it++) {
    try {
        myv = myClient.move("move", "Person",
            s.Person_Map[it->first]->dump2JSON(),
            GPS,
            "littleR");
        } catch (JsonRpcException &e) {
        cerr << e.what() << endl;
    }
    std::cout << myv.toStyledString() << std::endl;

  }
// Access value in Thing
  for (auto it = s.Thing_Map.begin(); it != s.Thing_Map.end(); it++) {
    try {
        myv = myClient.move("move", "Thing",
            s.Thing_Map[it->first]->dump2JSON(),
            GPS,
            it->first);
        } catch (JsonRpcException &e) {
        cerr << e.what() << endl;
    }
    std::cout << myv.toStyledString() << std::endl;

  }

  return 0;
}