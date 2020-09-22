#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H
#include<doorway.h>
#include<string>

namespace core::dungeon::common
{

class BlockedDoorWay: public Doorway
{
public:
    BlockedDoorWay();
    ~BlockedDoorWay();

    std::string description()override;

    char displayCharacter(Room::Direction direction) override;

    void setEntrance() override;

    void setExit()override;

    DoorwayType getDoorwayType() override;

};

}

#endif // BLOCKEDDOORWAY_H
