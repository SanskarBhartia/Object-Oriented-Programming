#ifndef _VTIME_H_
#define _VTIME_H_


#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <exception> 
#include "commonfiles.h"

// for Json::value

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>




class vTime
{
 private:
  std::string vtime;

public:
  vTime(std::string);
  vTime();
  std::string getTime();
  
  virtual Json::Value dump2JSON();
  virtual void JSON2Object(Json::Value);

};

#endif  /* _VTIME_H_ */