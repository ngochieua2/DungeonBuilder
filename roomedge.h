#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include<string>
#include<room.h>
#include<vector>

//class Room;

class RoomEdge
{
public:
    RoomEdge();
    ~RoomEdge();

    std::string description();
    char displayCharacter();
    virtual bool isPassage();

private:
    //Room *_room;

};

#endif // ROOMEDGE_H
