
#ifndef _GPS_H_
#define _GPS_H_
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>






using namespace std;
/*professors code
class GPS_DD
{
 private:
  double latitude;
  double longitude;
 public:
  explicit GPS_DD();
  explicit GPS_DD(double, double);
  double getLatitude();
  double getLongitude();
  double distance(GPS_DD);
  void dump();
};*/

class GPS
{
private:
    std::string location;
 public:
    GPS(std::string);
    GPS();

  Json::Value dump2JSON(); //outputing result with dump2JSON
};

#endif /* _GPS_H_ */
