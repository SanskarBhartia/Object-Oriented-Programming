#include "Person.h"
#include "Thing.h"
#include "GPS.h"
#include <json/json.h>
#include "Record.h"
#include "RTime.h"


//taken from code shown in class
Record::Record(GPS arg_location, Person arg_name, Thing arg_thing, Time arg_time)
{
    this->name = arg_name;
    this->location = arg_location;
    this->time = arg_time;
    this->thing = arg_thing;
}


Record::Record(GPS arg_location, Person arg_name, Person arg_name2, Thing arg_thing, Thing arg_thing2, Time arg_time)
{
    this->name = arg_name;
    this->name2 = arg_name2;
    this->location = arg_location;
    this->time = arg_time;
    this->thing2 = arg_thing2;
    this->thing = arg_thing;
}

Record::Record(GPS arg_location, Person arg_name, Person arg_name2, Time arg_time)
{
    this->location = arg_location;
    this->name = arg_name;
    this->name2 = arg_name2;
    this->time = arg_time;
}
Record::Record(GPS arg_location, Person arg_name, Time arg_time)
{
    this->location = arg_location;
    this->name = arg_name;
    this->time = arg_time;
}






//dump2JSON implementation

Json::Value
Record::dump2JSON
        (void)
{

    Json::Value result { };

    Json::Value jv_result;
    jv_result = (this->name).dump2JSON();
    if (!jv_result.isNull()) {
        result["person1"] = jv_result;
    }
    jv_result = (this->name2).dump2JSON();
    if (!jv_result.isNull()) {
        result["person2"] = jv_result;
    }
    jv_result = (this->time).dump2JSON();
    if (!jv_result.isNull()) {
        result["time"] = jv_result;
    }
    jv_result = (this->thing).dump2JSON();
    if (!jv_result.isNull()) {
        result["thing"] = jv_result;
    }
    jv_result = (this->thing2).dump2JSON();
    if (!jv_result.isNull()) {
        result["thing2"] = jv_result;
    }
    jv_result = (this->location).dump2JSON();
    if (!jv_result.isNull()) {
        result["location"] = jv_result;
    }
    return result;
}
