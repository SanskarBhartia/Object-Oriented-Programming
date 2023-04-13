
#ifndef _RTIME_H_
#define _RTIME_H_
#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <json/json.h>




class Time {
public:
    std::string time;
    Time(std::string);
    Time();

    Json::Value dump2JSON(); //using dump2JSON
};


#endif
