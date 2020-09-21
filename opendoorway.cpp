#include "opendoorway.h"

OpenDoorWay::OpenDoorWay(){}

OpenDoorWay::~OpenDoorWay(){}


std::string OpenDoorWay::description(){
    return "an Open Door to another chamber";
}

void OpenDoorWay::setEntrance(){
    Entrance = false;
}

void OpenDoorWay::setExit(){
    Exit = false;
}

Doorway::DoorwayType OpenDoorWay::getDoorwayType()
{
    return DoorwayType::OpenDoorway;
}
