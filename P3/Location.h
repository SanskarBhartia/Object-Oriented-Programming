#ifndef _LOCATION_H_
#define _LOCATION_H_


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
#include "commonfiles.h"

// for Json::value

#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>


class Location
{
 private:
  std::string location;
  
public:
  Location(std::string);
  Location();
  std::string getLocation();
  
  virtual Json::Value dump2JSON();
  virtual void JSON2Object(Json::Value);
};

#endif  /* _LOCATION_H_ */

