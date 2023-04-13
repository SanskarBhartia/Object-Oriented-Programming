
#ifndef _THING_H_
#define _THING_H_


#include "Person.h"
#include "GPS.h"

// Thing.h



class Thing
{
 private:
    std::string thing;

 public:
  Thing(std::string);
  Thing();



  Json::Value dump2JSON(); //using dump2JSON

};

#endif /* _THING_H_ */
