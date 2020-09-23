#ifndef ROOM_H
#define ROOM_H
#include <string>
#include <vector>
#include <roomedge.h>
#include <monster.h>
#include <weapon.h>
#include <consumable.h>

namespace core::dungeon
{

class RoomEdge;

class Room
{
public:
    Room();
    Room(int id);
    ~Room();

    virtual std::string description();

    int id();

    core::items::Item* item();
    void setItem(core::items::Item* newItem);

    core::creatures::AbstractCreature* creature();
    void setCreature(core::creatures::AbstractCreature* newCreature);


    enum class Direction : unsigned {
        North, South, East, West
    };


    void setEdge(RoomEdge *edge, Direction direction);

    RoomEdge* edgeAt(Direction direction);


    RoomEdge* getRoomEdge();

    std::string edgeDescription(Direction direction);

    std::string creatureDescription();

    std::string itemDescription();

    std::vector<std::string> display();

protected:
    int _id{NULL};

    RoomEdge *_roomEdge{nullptr};

    std::vector <std::string> roomMap;

    std::vector <RoomEdge*> EdgesVector;

    core::creatures::AbstractCreature *_abstractCreature{nullptr};
    core::items::Item *_item{nullptr};


};

}

#endif // ROOM_H
