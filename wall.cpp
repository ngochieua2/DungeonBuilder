#include "wall.h"

using core::dungeon::Wall;

Wall::Wall(){}

Wall::~Wall(){}

std::string Wall::description()
{
    return "wall ";
}

char Wall::displayCharacter(Room::Direction direction)
{
    if(direction == Room::Direction::North || direction == Room::Direction::South){
        return '-';
    }
    else {
        return '|';
    }
}


bool Wall::isPassage(){
    return false;
}
