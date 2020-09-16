#include "room.h"
#include<vector>



Room::Room(int id): _id{id}
{}

Room::~Room(){}


int Room::id(){
    return _id;
}

void Room::setNorth(RoomEdge edge){
    _Edges.at(0) = edge;
};

void Room::setEast(RoomEdge edge){
    _Edges.at(1) = edge;
};

void Room::setSouth(RoomEdge edge){
    _Edges.at(2) = edge;
}

void Room::setWest(RoomEdge edge){
    _Edges.at(3) = edge;
}

RoomEdge Room::getNorth(){
    return _Edges.at(0);
}

RoomEdge Room::getEast(){
    return _Edges.at(1);
}

RoomEdge Room::getSouth(){
    return _Edges.at(2);
}

RoomEdge Room::getWest(){
    return _Edges.at(3);
}
