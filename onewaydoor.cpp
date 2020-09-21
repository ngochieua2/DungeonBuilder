#include "onewaydoor.h"

OneWayDoor::OneWayDoor(){}

OneWayDoor::~OneWayDoor(){}

std::string OneWayDoor::description(){
    if (isEntrance()){
        return "The Entrance to the dungeon level ";
    }
    else if (isExit()) {
        return "The Exit of the dungeon level ";
    }
    else {
        return "an One-way Door to another chamber ";
    }
}

void OneWayDoor::setEntrance(){
    Entrance = true;
}

void OneWayDoor::setExit(){
    Exit = true;
}

Doorway::DoorwayType OneWayDoor::getDoorwayType()
{
    return DoorwayType::OneWayDoor;
}


