#include "wall.h"

Wall::Wall(){}

Wall::~Wall(){}

std::string Wall::description()
{
    return "wall ";
};


bool Wall::isPassage(){
    return false;
}
