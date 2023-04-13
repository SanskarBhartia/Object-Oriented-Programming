
#include "Person.h"
Person::Person(std::string arg_name)
{
  this->name = arg_name;
}

Person::Person()
{
  this->name = "";
}

std::string Person::getName() {
  return name;
}


Json::Value
Person::dump2JSON
(void)
{
  Json::Value result { };
  

  if (this->name != "")
    {
      result["Name(s)"] = this->name;
    }

  return result;
}

void Person::JSON2Object
(Json::Value arg_jv)
{
  name = arg_jv["Name(s)"].asString();

}


