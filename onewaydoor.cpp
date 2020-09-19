#include "onewaydoor.h"

OneWayDoor::OneWayDoor(){}

OneWayDoor::~OneWayDoor(){}

std::string OneWayDoor::description(){
    if (isEntrance()){
        return "The Entrance ";
    }
    else if (isExit()) {
        return "The Exit ";
    }
    else {
        return "an One-way Door ";
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


