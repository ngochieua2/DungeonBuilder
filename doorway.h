#ifndef DOORWAY_H
#define DOORWAY_H
#include<roomedge.h>

class Doorway : public RoomEdge
{
public:
    Doorway();
    ~Doorway();

    std::string description();

    void connect (Doorway *opposite);

    bool isEntrance();
    bool isExit();

    bool isPassage();

    virtual void setEntrance();

    virtual void setExit();

protected:
    bool Entrance{false};
    bool Exit{false};
};

#endif // DOORWAY_H
