#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H
#include<doorway.h>
#include<string>

namespace core::dungeon::common
{

class OneWayDoor: public Doorway
{
public:
    OneWayDoor();
    ~OneWayDoor();

    std::string description()override;

    char displayCharacter(core::dungeon::Room::Direction direction);

    void setEntrance() override;

    void setExit() override;

    DoorwayType getDoorwayType()override;
};

}

#endif // ONEWAYDOOR_H
