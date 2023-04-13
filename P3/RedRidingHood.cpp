
#include "Person.h"
#include "Thing.h"
#include "Location.h"
#include "vTime.h"
#include "Record.h"
#include "commonfiles.h"

int
main(int argc, char *argv[])
{
  //first record

  vTime Onetime{"12:00PM"};
  Location Onelocation{"Grandma's house"};
  Thing Onething{"Cap"};
  Person Oneperson{"Red riding hood"};

  Record one(Onething, Oneperson, Onelocation, Onetime);

  vTime jsonOnetime;
  Location jsonOnelocation;
  Thing jsonOnething;
  Person jsonOneperson;

  Record onejson(jsonOnething, jsonOneperson, jsonOnelocation, jsonOnetime); //create empty record
  Json::Value firstjson = one.dump2JSON(); //assign firstjson to original filled record
  Json::Value outfirstjson; // declare
  char fileone[6] = {'1', '.', 'j', 's', 'o', 'n'}; //create file name
  myJSON2File(fileone, &firstjson); // put dump into fileone
  myFile2JSON(fileone, &outfirstjson); // put fileone into outfirstjson
  onejson.JSON2Object(outfirstjson); //put outfirstjson info into onejson record
  std::cout << (onejson.dump2JSON()).toStyledString() << std::endl; //print onejson record
  
  //second record
  vTime Twotime{"Next day, 8:00AM"};
  Location Twolocation{"Grandma's house"};
  Thing Twothing{"Piece of cake, Bottle of wine"};
  Person Twoperson{"Little Red Riding Hood's Mother"};

  Record two(Twothing, Twoperson, Twolocation, Twotime);
 
  vTime jsonTwotime;
  Location jsonTwolocation;
  Thing jsonTwothing;
  Person jsonTwoperson;
  
  Record twojson(jsonTwothing, jsonTwoperson, jsonTwolocation, jsonTwotime);
  Json::Value secondjson = two.dump2JSON();
  Json::Value outsecondjson;
  char filetwo[6] = {'2', '.', 'j', 's', 'o', 'n'};
  myJSON2File(filetwo, &secondjson);
  myFile2JSON(filetwo, &outsecondjson); //when commented prints but it is null
  twojson.JSON2Object(outsecondjson);
  std::cout << (twojson.dump2JSON()).toStyledString() << std::endl;
  
  //third record
 
  vTime Threetime{"9:26AM"};
  Location Threelocation{"In the Woods"};
  Thing Threething{"No Object"};
  Person Threeperson{"Little Red Riding Hood, Wolf"};

  Record three(Threething, Threeperson, Threelocation, Threetime);

  vTime jsonThreetime;
  Location jsonThreelocation;
  Thing jsonThreething;
  Person jsonThreeperson;

  Record threejson(jsonThreething, jsonThreeperson, jsonThreelocation, jsonThreetime);
  Json::Value thirdjson = three.dump2JSON();
  Json::Value outthirdjson;
  char filethree[6] = {'3', '.', 'j', 's', 'o', 'n'};
  myJSON2File(filethree, &thirdjson);
  myFile2JSON(filethree, &outthirdjson);
  threejson.JSON2Object(outthirdjson);
  std::cout << (threejson.dump2JSON()).toStyledString() << std::endl;

  //fourth record

  vTime Fourtime{"9:44AM"};
  Location Fourlocation{"Grandma's house right outside the woods next to three large oak trees"};
  Thing Fourthing{"No Object"};
  Person Fourperson{"Grandmother"};

  Record four(Fourthing, Fourperson, Fourlocation, Fourtime);

  vTime jsonFourtime;
  Location jsonFourlocation;
  Thing jsonFourthing;
  Person jsonFourperson;

  Record fourjson(jsonFourthing, jsonFourperson, jsonFourlocation, jsonFourtime);
  Json::Value fourthjson = four.dump2JSON();
  Json::Value outfourthjson;
  char filefour[6] = {'4', '.', 'j', 's', 'o', 'n'};
  myJSON2File(filefour, &fourthjson);
  myFile2JSON(filefour, &outfourthjson);
  fourjson.JSON2Object(outfourthjson);
  std::cout << (fourjson.dump2JSON()).toStyledString() << std::endl;

 return 0;
}