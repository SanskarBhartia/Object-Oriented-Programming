
// for Json::value
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

using namespace jsonrpc;
using namespace std;

// std::map (key, value pairs)

class Myhw5Server : public hw5Server
{
public:
  Myhw5Server(AbstractServerConnector &connector, serverVersion_t type);
  virtual Json::Value move(const std::string& action,
			   const std::string& class_id,
			   const Json::Value& json_object,
			   const Json::Value& location,
			   const std::string& object_id);
  virtual Json::Value done();
  std::map<std::string, Thing *> Thing_Map;
  std::map<std::string, Person *> Person_Map;
  bool complete = false;
};

Myhw5Server::Myhw5Server(AbstractServerConnector &connector, serverVersion_t type)
  : hw5Server(connector, type)
{
  std::cout << "Myhw5Server Object created" << std::endl;
}

// member functions

Json::Value
Myhw5Server::move
(const std::string& action, const std::string& class_id,
 const Json::Value& json_object, const Json::Value& location,
 const std::string& object_id)
{
  // int error_code = 0;
  Json::Value result;

    Person * lv_person_ptr;
    if (Person_Map.find(object_id) != Person_Map.end()) {
      lv_person_ptr = Person_Map[object_id];
    } else {
      lv_person_ptr = new Person {};
      Person_Map[object_id] = lv_person_ptr;
    }
    lv_person_ptr -> JSON2Object(json_object);

    result = json_object;

    std::cout << result.toStyledString() << std::endl;
    return result;



  Json::Value result2;

    Thing * lv_thing_ptr;
    if (Thing_Map.find(object_id) != Thing_Map.end()) {
      lv_thing_ptr = Thing_Map[object_id];
    } else {
      lv_thing_ptr = new Thing {};
      Thing_Map[object_id] = lv_thing_ptr;
    }

    lv_thing_ptr -> JSON2Object(json_object);

    result2 = json_object;

    std::cout << result.toStyledString() << std::endl;
    return result2;
 }


Json::Value
Myhw5Server::done()
{
  Json::Value result;
  result["sent"] = "The Objects Have Been Sent";
  std::cout << result.toStyledString() << std::endl;
  complete = true;
  return result;
  
 }