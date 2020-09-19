#include "lockeddoor.h"

LockedDoor::LockedDoor(){}

LockedDoor::~LockedDoor(){}

std::string LockedDoor::description(){
    return "A Locked Door ";
}

void LockedDoor::setEntrance(){
    Entrance = false;
}

void LockedDoor::setExit(){
    Exit = false;
}

Doorway::DoorwayType LockedDoor::getDoorwayType()
{
    return DoorwayType::LockedDoorway;
}
