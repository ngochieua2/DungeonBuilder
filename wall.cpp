#include "wall.h"

using core::dungeon::Wall;

Wall::Wall(){}

Wall::~Wall(){}

std::string Wall::description()
{
    return "wall ";
}


bool Wall::isPassage(){
    return false;
}
