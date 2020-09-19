#include "blockeddoorway.h"

BlockedDoorWay::BlockedDoorWay(){}

BlockedDoorWay::~BlockedDoorWay(){}

std::string BlockedDoorWay::description(){
    return "a Block Door ";
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
