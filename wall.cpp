#include "wall.h"


Wall::Wall(){}

Wall::~Wall(){};

char Wall::RoomEdge::displayCharacter(Room::Direction type){
    if(type == Room::Direction::North || type == Room::Direction::South) return '-';
    else return '|';
}
