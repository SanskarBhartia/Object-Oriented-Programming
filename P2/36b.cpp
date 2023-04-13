
#include "Person.h"
#include "Thing.h"
#include "Record.h"
#include <json/json.h>
#include "RTime.h"

int
main(int argc, char *argv[])
{
  //making person, GPS,Time and thing


  Person LRRH("Little Red Riding Hood");
  Person mother("Little Red Riding Hood's Mother");
  Person wolf("Wolf");
  Person grandma("Grandma") ;
  GPS location("Little Red Riding Hood's Home");
  GPS Forest_location2("Beginning of the woods");
  GPS Grandma_Location("Grandma's house under the large oak trees");
  Time Morning("Sometime in the morning");
  Thing Cap("Cap");
  Thing Cake("Cake");
  Thing Wine("Wine");





  std::cout << "---------Record 1-------------\n";
  Record record1(location, LRRH, Cap, Morning);
  std::cout << (record1.dump2JSON()).toStyledString() << std::endl;

  std::cout << "---------Record 2-------------\n";
  Record record2(location, mother, LRRH, Wine, Cake, Morning);
  std::cout << (record2.dump2JSON()).toStyledString() << std::endl;

  std::cout << "---------Record 3-------------\n";
  Record record3(Forest_location2, LRRH, wolf, Morning);
  std::cout << (record3.dump2JSON()).toStyledString() << std::endl;

  std::cout << "---------Record 4-------------\n";
  Record record4(Grandma_Location, grandma, Morning);
  std::cout << (record4.dump2JSON()).toStyledString() << std::endl;

  return 0;
}
