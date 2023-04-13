#include<string>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Person.h"
using std::string;

Person::Person(){};  
// Person::Person(string description)
// {
//     setDescription(description);
// }
Person::Person(string name, string description)
{
    setName(name);
    setDescription(description);
}

string Person::getName()
{
    return name;
};
void Person::setName(string name)
{
    this->name = name;
};
string Person::getDescription()
{
    return description;
}
void Person::setDescription(string description)
{
    this->description = description;
};
Json::Value Person::dump2JSON()
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
bool Person::JSON2Object(Json::Value input)
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
    return result;
}

