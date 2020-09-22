#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <roomedge.h>
#include <monster.h>
#include <weapon.h>
#include <consumable.h>



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

    Item* item();
    void setItem(Item* newItem);

    AbstractCreature* creature();
    void setCreature(AbstractCreature* newCreature);


    enum class Direction : unsigned {
        North, South, East, West
    };


    void setEdge(RoomEdge *edge, Direction direction);

    RoomEdge* edgeAt(Direction direction);


    RoomEdge* getRoomEdge();

    std::string edgeDescription(Direction direction);

    enum class roomType : unsigned {
        quartzChamber,
        rockChamber
    };

    roomType getRoomType();

protected:
    int _id{NULL};

    RoomEdge *_roomEdge{nullptr};

    //std::vector <std::string> _roomVector;

    std::vector <RoomEdge*> EdgesVector;

    AbstractCreature *_abstractCreature{nullptr};
    Item *_item{nullptr};

    roomType _roomType{NULL};

};

#endif // ROOM_H
