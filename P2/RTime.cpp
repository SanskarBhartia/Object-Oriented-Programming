
// https://github.com/sfelixwu/Person_and_Thing/blob/main/JvTime.h


#include "RTime.h"
#include "string.h"

Time::Time(std::string arg_time)
{
    this->time= arg_time;
}

Time::Time()
{
    this->time = "";
}
Json::Value
Time::dump2JSON
()
{
  Json::Value result {};
    if (this->time != "")
    {
        result["time"] = this->time;
    }

#ifdef _ECS36B_DEBUG_
  std::cout << result.toStyledString() << std::endl;
#endif /* _ECS36B_DEBUG_ */

  return result;
}
