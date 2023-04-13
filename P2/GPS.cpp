


// https://github.com/sfelixwu/Person_and_Thing/blob/main/GPS.cpp

#include "GPS.h"

GPS::GPS()
{
  this->location = "";
}


GPS::GPS(std::string arg_location)
{
  this->location = arg_location;
}


Json::Value
GPS::dump2JSON
()
{
  Json::Value result;
  if (this->location != "")
    {
      result["location"] = this->location;
    }

  return result;
}
