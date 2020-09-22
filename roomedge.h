#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include<string>
#include<room.h>
#include<vector>

namespace core::dungeon{

class RoomEdge
{
public:
    RoomEdge();
    ~RoomEdge();

    virtual std::string description();
    virtual char displayCharacter(Room::Direction direction);
    virtual bool isPassage();

    virtual bool isEntrance();
    virtual bool isExit();

    virtual void setEntrance();

    virtual void setExit();

    enum class DoorwayType : unsigned {
        Undefine = 0,
        OpenDoorway = 1,
        OneWayDoor = 2,
        LockedDoorway = 3,
        BlockedDoorway = 4,
    };

    virtual DoorwayType getDoorwayType();


protected:
    bool Entrance{false};
    bool Exit{false};
};

}

#endif // ROOMEDGE_H
