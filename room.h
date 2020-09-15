#ifndef ROOM_H
#define ROOM_H
#include<string>

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

private:
    int _id;
    RoomEdge *roomEdge;
};

#endif // ROOM_H
