#ifndef _RECORD_H_
#define _RECORD_H_

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

#include "Person.h"
#include "Thing.h"
#include "Location.h"
#include "vTime.h"



class Record {
  private:
  public:
    Person person;
    Thing thing;
    Location location;
    vTime vtime;
    Record(Thing, Person, Location, vTime);

    virtual Json::Value dump2JSON();
    virtual void JSON2Object(Json::Value);

};

#endif  /* _RECORD_H_ */