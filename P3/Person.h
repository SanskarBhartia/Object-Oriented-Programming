
#ifndef _PERSON_H_
#define _PERSON_H_

// Person.h

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



class Person
{
 private:
  std::string name;
  
public:
  Person(std::string);
  Person();
  std::string getName();
  virtual Json::Value dump2JSON();
  virtual void JSON2Object(Json::Value);
};

#endif  /* _PERSON_H_ */

