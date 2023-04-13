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
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

int main() {

  Person littleR;
  littleR.setName("girl");
  littleR.setDescription("a dear little girl");

  Thing cap;
  cap.setName("cap");
  cap.setDescription("red velvet");

  Thing cake, wine;
  cake.setName("Piece of Cake");
  wine.setName("Bottle of Wine");

  HttpClient httpclient("http://127.0.0.1:7375");
  hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value GPS;
  GPS["location"] = "Forest";


//Take the Json information and outputs it
  try {
    myv = myClient.move("move", "Person", littleR.dump2JSON(), GPS, "littleR");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  try {
    myv = myClient.move("move", "Thing", cap.dump2JSON(), GPS, "cap");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  try {
    myv = myClient.move("move", "Thing", cake.dump2JSON(), GPS, "cake");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  try {
    myv = myClient.move("move", "Thing", wine.dump2JSON(), GPS, "wine");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  Json::Value finish;

//Tells the client that the process has finished and outputs a done statement in Json form
  try {
    finish = myClient.done();
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << finish.toStyledString() << std::endl;


  HttpServer httpserver(7374);
  Myhw5Server s(httpserver,
		JSONRPC_SERVER_V1V2); // hybrid server (json-rpc 1.0 & 2.0)
  s.StartListening();
  getchar();

  s.StopListening();

  
  return 0;
}