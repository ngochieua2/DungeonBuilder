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

    std::string discription();
    char displayCharacter();
    bool isPassage();

private:
    //Room *_room;

};

#endif // ROOMEDGE_H
