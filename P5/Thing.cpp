#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include "Thing.h"

using std::string;

string Thing::getName()
{
    return name;
}
void Thing::setName(string name)
{
    this->name = name;
};
string Thing::getDescription()
{
    return description;
}
void Thing::setDescription(string description)
{
    this->description = description;
};
Thing::Thing(){};
Thing::Thing(string name, string description)
{
    setName(name);
    setDescription(description);
}
Json::Value Thing::dump2JSON()
{
    Json::Value result;
    if (this->name != "")
    {
        result["name"] = this->name;
    }
    if (this->description != "")
    {
        result["description"] = this->description;
    }
    return result;
};
bool Thing::JSON2Object(Json::Value input)
//TO BE CONTINUTED
{
    bool result = true;
    if (input["name"].type())
    {
        this->name = input["name"].asString();
    }
    if (input["description"].type())
    {
        this->description = input["description"].asString();
    }
}
