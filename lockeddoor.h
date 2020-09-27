#ifndef LOCKEDDOOR_H
#define LOCKEDDOOR_H
#include <doorway.h>
#include <string>

namespace core::dungeon::common
{

class LockedDoor: public Doorway
{
public:
    LockedDoor();
    ~LockedDoor();

     std::string description()override;

     char displayCharacter() override;

     /*
      * if it is LockedDoor,
      * it will not entrance or exit
      */
     void setEntrance()override;

     void setExit() override;

};

}

#endif // LOCKEDDOOR_H
