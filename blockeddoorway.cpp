#include "blockeddoorway.h"

using core::dungeon::Doorway;
using core::dungeon::common::BlockedDoorWay;

BlockedDoorWay::BlockedDoorWay(){}

BlockedDoorWay::~BlockedDoorWay(){}

std::string BlockedDoorWay::description(){
    return "a Block Door ";
}

char BlockedDoorWay::displayCharacter(Room::Direction direction)
{
    //check opporite is one way or not
    return 'X';
}

void BlockedDoorWay::setEntrance(){
    Entrance = false;
}

void BlockedDoorWay::setExit(){
    Exit = false;
}

Doorway::DoorwayType BlockedDoorWay::getDoorwayType()
{
    return DoorwayType::BlockedDoorway;
}
