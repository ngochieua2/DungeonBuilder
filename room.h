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


    void setNorth(RoomEdge *edge);
    void setEast(RoomEdge *edge);

    void setSouth(RoomEdge *edge);

    void setWest(RoomEdge *edge);

    RoomEdge* getNorth();

    RoomEdge* getEast();

    RoomEdge* getSouth();

    RoomEdge* getWest();

    RoomEdge* getRoomEdge(){
        return _roomEdge;
    }

private:
    int _id;

    RoomEdge *_roomEdge;

    //std::vector <std::string> _roomVector;

    std::vector <RoomEdge*> _EdgesVector;

};

#endif // ROOM_H
