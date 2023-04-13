#include "Location.h"
Location::Location(std::string arg_location)
{
  this->location = arg_location;
}

Location::Location()
{
  this->location = "";
}

std::string Location::getLocation() {
  return location;
}

Json::Value
Location::dump2JSON
(void)
{
  Json::Value result { };

  if (this->location != "")
    {
      result["GPS"] = this->location;
    }

  return result;
}

void Location::JSON2Object
(Json::Value arg_jv)
{
  location = arg_jv["GPS"].asString();



/*
  if ((arg_jv.isNull() == true) ||
      (arg_jv.isObject() != true))
    {
      return false;
    }

    if (arg_jv["Location"] != "" || this->location = (arg_jv["Location"]).isString();) {
      this->location = arg_jv["Location"];
    }

    //check if string
    //check if null

  if (((arg_jv["latitude"]).isNull() == true) ||
      ((arg_jv["longitude"]).isNull() == true) ||
      ((arg_jv["latitude"]).isDouble() != true) ||
      ((arg_jv["longitude"]).isDouble() != true))
    {
      return false;
    }

  // we allow GPS_DD to be modified (for mobility)
  this->latitude = (arg_jv["latitude"]).asDouble();
  this->longitude = (arg_jv["longitude"]).asDouble();
  */

}
