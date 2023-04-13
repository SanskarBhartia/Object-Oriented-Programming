
//https://github.com/sfelixwu/Person_and_Thing/blob/main/Person.cpp


#include "Person.h"

Person::Person(std::string arg_name)
{
  this->name = arg_name;
}

Person::Person()
{

  this->name = "";

}

Json::Value
Person::dump2JSON     //dump function
(void)
{
  Json::Value result { };
  if (this->name != "")
    {
      result["name"] = this->name;
    }
    
  return result;
}
