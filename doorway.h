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

    char displayCharacter() override;

    void connect (Doorway *opposite);

    bool isEntrance() override;
    bool isExit() override;

    bool isPassage() override;

    void setEntrance() override;

    void setExit() override;

    bool isOneway();

protected:
    Doorway *_oppositeDoor{nullptr};
    bool oneway{false};
};

}

#endif // DOORWAY_H
