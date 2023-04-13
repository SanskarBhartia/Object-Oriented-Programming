#include "Record.h"
#include "Person.h"
#include "Thing.h"
#include "Location.h"
#include "vTime.h"

Record::Record(Thing thing, Person person, Location location, vTime vtime) {
  this->person = person;
  this->thing = thing;
  this->location = location;
  this->vtime = vtime;


}

Json::Value Record::dump2JSON() {
  Json::Value result;

  result["Location"] = location.dump2JSON();
  result["Time"] = vtime.dump2JSON();
  result["Person"] = person.dump2JSON();
  result["Thing"] = thing.dump2JSON();

  return result;

}

void Record::JSON2Object
(Json::Value arg_jv)
{
  thing.JSON2Object(arg_jv["Thing"]);
  location.JSON2Object(arg_jv["Location"]);
  person.JSON2Object(arg_jv["Person"]);
  vtime.JSON2Object(arg_jv["Time"]);
}

