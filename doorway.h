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

    /*!
     * Function connect use to store infor of
     * the door in opposite it connects with.
     * With entrance and exit, they will not connect
     * with anything, so their opposite will be nullptr.
     * @param opposite is poiner of the door connect with
     */
    void connect (Doorway *opposite);

    bool isEntrance() override;

    bool isExit() override;

    /*!
     * Function isPassage is used to distinguish wall,
     * entrance, exit (false) or a normal doorway (true)
     */
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
