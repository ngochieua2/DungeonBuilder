#include "room.h"

Room::Room(){}

Room::Room(int id): _id{id}{
    EdgesVector.assign(4,_roomEdge);
}

Room::~Room(){
    delete[] _roomEdge;
    for (int i = 0; i < (int)EdgesVector.size(); ++ i){
        delete[] EdgesVector[i];
    }
    delete _item;
    delete _abstractCreature;
}

std::string Room::description()
{
    return "a room\n";
}


int Room::id(){
    return _id;
}

Item *Room::item()
{
    return _item;
}

void Room::setItem(Item *newItem)
{
    _item = newItem;
}

AbstractCreature *Room::creature()
{
    return _abstractCreature;
}

void Room::setCreature(AbstractCreature *newCreature)
{
    _abstractCreature = newCreature;
}

void Room::setEdge(RoomEdge *edge, Direction direction){
    if(direction == Direction::North){
        EdgesVector.at(0) = edge;
    }
    else if (direction == Direction::East) {
        EdgesVector.at(1) = edge;
    }
    else if (direction == Direction::South) {
        EdgesVector.at(2) = edge;
    }
    else {
        EdgesVector.at(3) = edge;
    }
}

RoomEdge* Room::edgeAt(Direction direction){
    if(direction == Direction::North){
        return EdgesVector.at(0);
    }
    else if (direction == Direction::East) {
        return  EdgesVector.at(1);
    }
    else if (direction == Direction::South) {
        return EdgesVector.at(2);
    }
    else {
        return EdgesVector.at(3);
    }
}

RoomEdge* Room::getRoomEdge(){
    return _roomEdge;
}

std::string Room::edgeDescription(Room::Direction direction)
{
    return edgeAt(direction)->description();
}

std::string Room::creatureDescription()
{
    if(_abstractCreature == nullptr){
        return "There is no monster to fight\n";
    }
    else {
        return _abstractCreature->name();
    }
}

std::string Room::itemDescription()
{
    if(_item == nullptr){
        return "There is no Item to pick up\n";
    }
    else {
        return _item->name();
    }
}












