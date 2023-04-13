
#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include "RTime.h"
#include <json/json.h>




class Record{

public:
    GPS location;
    Person name;
    Person name2;
    Time time;
    Thing thing;
    Thing thing2;

    Record(GPS, Person, Thing, Time);
    Record(GPS, Person, Person, Thing, Thing, Time);
    Record(GPS, Person, Person, Time);
    Record(GPS, Person, Time);

    Json::Value dump2JSON(); //using dump2JSON

};
