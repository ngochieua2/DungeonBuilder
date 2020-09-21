#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <array>
#include<roomedge.h>

class RoomEdge;

class Room
{
public:
    Room();
    Room(int id);
    ~Room();

    virtual std::string description();

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

    std::string edgeDescription(Direction direction);

protected:
    int _id;

    RoomEdge *_roomEdge{nullptr};

    //std::vector <std::string> _roomVector;

    std::vector <RoomEdge*> EdgesVector;

};

#endif // ROOM_H
