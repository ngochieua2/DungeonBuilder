#ifndef DOORWAY_H
#define DOORWAY_H
#include<roomedge.h>

namespace core::dungeon
{

class Doorway : public RoomEdge
{
public:
    Doorway();
    ~Doorway();

    std::string description()override;

    char displayCharacter(core::dungeon::Room::Direction direction);

    void connect (Doorway *opposite);

    bool isEntrance() override;
    bool isExit() override;

    bool isPassage() override;

    void setEntrance() override;

    void setExit() override;

    bool isOneWayDoor();

    DoorwayType getDoorwayType() override;

protected:
    Doorway *_oppositeDoor{nullptr};
    bool oneWay{false};
};

}

#endif // DOORWAY_H
