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
}

std::string Room::description()
{
    return "a room\n";
}


int Room::id(){
    return _id;
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









