#include "room.h"
#include<vector>



Room::Room(int id): _id{id}
{}

Room::~Room(){
    delete _roomEdge;
    for (int i = 0; i < _EdgesVector.size(); ++ i){
        delete _EdgesVector[i];
    }

}


int Room::id(){
    return _id;
}

void Room::setNorth(RoomEdge *edge){
    _EdgesVector.at(0) = edge;
};

void Room::setEast(RoomEdge *edge){
    _EdgesVector.at(1) = edge;
};

void Room::setSouth(RoomEdge *edge){
    _EdgesVector.at(2) = edge;
}

void Room::setWest(RoomEdge *edge){
    _EdgesVector.at(3) = edge;
}

RoomEdge* Room::getNorth(){
    return _EdgesVector.at(0);
}

RoomEdge* Room::getEast(){
    return _EdgesVector.at(1);
}

RoomEdge* Room::getSouth(){
    return _EdgesVector.at(2);
}

RoomEdge* Room::getWest(){
    return _EdgesVector.at(3);
}
