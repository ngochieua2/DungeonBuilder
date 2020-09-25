#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include<string>
//#include<room.h>
#include<vector>

namespace core::dungeon
{

class Room;

class RoomEdge
{
public:
    RoomEdge();
    virtual ~RoomEdge();

    virtual std::string description();

    void setChar(char sChar);

    virtual char displayCharacter();
    virtual bool isPassage();

    virtual bool isEntrance();
    virtual bool isExit();

    virtual void setEntrance();

    virtual void setExit();

protected:
    bool Entrance{false};
    bool Exit{false};
    char character{};
};

}

#endif // ROOMEDGE_H
