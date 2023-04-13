#include "vTime.h"
#include "commonfiles.h"

vTime::vTime(std::string arg_vtime)
{
  this->vtime = arg_vtime;
}

vTime::vTime()
{
  this->vtime = "";
}

std::string vTime::getTime() {
  return vtime;
}

Json::Value
vTime::dump2JSON
(void)
{
  Json::Value result { };

  if (this->vtime != "")
    {
      result["Time of day"] = this->vtime;
    }

  return result;
}

void vTime::JSON2Object
(Json::Value arg_jv)
{
  vtime = arg_jv["Time of day"].asString();

}
