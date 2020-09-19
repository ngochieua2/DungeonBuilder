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

    bool isEntrance() override;
    bool isExit() override;

    bool isPassage() override;

    void setEntrance() override;

    void setExit() override;

    DoorwayType getDoorwayType() override;

protected:
    Doorway *_doorway{nullptr};
};

#endif // DOORWAY_H
