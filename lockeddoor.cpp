#include "lockeddoor.h"

using core::dungeon::Doorway;
using core::dungeon::common::LockedDoor;

LockedDoor::LockedDoor(){}

LockedDoor::~LockedDoor(){}

std::string LockedDoor::description(){
    return "A Locked Door to another chamber";
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
