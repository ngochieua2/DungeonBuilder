#ifndef ROOMEDGE_H
#define ROOMEDGE_H
#include<string>
#include<room.h>
#include<vector>

class RoomEdge
{
public:
    RoomEdge();
    ~RoomEdge();

    std::string discription();
    char displayCharacter(Room::Direction type);
    bool isPassage();

private:
    Room *_room;

};

#endif // ROOMEDGE_H
