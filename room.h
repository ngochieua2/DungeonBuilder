#ifndef ROOM_H
#define ROOM_H
#include<string>
#include<vector>
#include<roomedge.h>

class RoomEdge;

class Room
{
public:
    Room(int id);
    ~Room();

    std::string description();

    //std::string[] display();

    int id();
    //Item item();
    //creature()
    //setCreature



    enum class Direction : unsigned {
        North, South, East, West
    };


    void setEdge(RoomEdge *edge, Direction direction);

    RoomEdge* edgeAt(Direction direction);


    RoomEdge* getRoomEdge();

private:
    int _id;

    RoomEdge *_roomEdge;

    //std::vector <std::string> _roomVector;

    std::vector <RoomEdge*> EdgesVector;

};

#endif // ROOM_H
