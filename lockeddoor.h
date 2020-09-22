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

     char displayCharacter(Room::Direction direction) override;

     void setEntrance()override;

     void setExit() override;

     DoorwayType getDoorwayType()override;

};

}

#endif // LOCKEDDOOR_H
