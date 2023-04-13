#include "Thing.h"

#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <exception> 
#include <time.h>

// for Json::value

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>




Thing::Thing(std::string arg_thing)
{
  this->thing = arg_thing;
}

Thing::Thing()
{
  this->thing = "";
}

std::string Thing::getThing() {
  return thing;
}

Json::Value
Thing::dump2JSON
(void)
{
  Json::Value result { };

  if (this->thing != "")
    {
      result["Object(s)"] = this->thing;
    }

  return result;
}

void Thing::JSON2Object
(Json::Value arg_jv)
{
  thing = arg_jv["Object(s)"].asString();

}
