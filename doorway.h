#ifndef DOORWAY_H
#define DOORWAY_H
#include<roomedge.h>

class Doorway : public RoomEdge
{
public:
    Doorway();
    ~Doorway();

    std::string description()override;

    void connect (Doorway *opposite);

    Doorway *getOpposite();

    bool isEntrance();
    bool isExit();

    bool isPassage();

    virtual void setEntrance();

    virtual void setExit();


    enum class DoorwayType : unsigned {
        None = 0,
        OpenDoorway = 1,
        OneWayDoor = 2,
        LockedDoorway = 3,
        BlockedDoorway = 4,
    };

    virtual DoorwayType getDoorwayType();

protected:
    Doorway *_doorway{nullptr};
    bool Entrance{false};
    bool Exit{false};
};

#endif // DOORWAY_H
