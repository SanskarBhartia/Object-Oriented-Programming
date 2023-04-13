// https://github.com/sfelixwu/Person_and_Thing/blob/main/Thing.h
#include "Thing.h"


Thing::Thing(std::string arg_thing)
{
    this->thing= arg_thing;

}


Thing::Thing
()
{
  this->thing = "";

}

Json::Value Thing::dump2JSON
(void)
{
  Json::Value result { };

  if (this->thing != "")
    {
      result["thing"] = this->thing;
    }

  return result;
}
