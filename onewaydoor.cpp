#include "onewaydoor.h"

OneWayDoor::OneWayDoor(){}

OneWayDoor::~OneWayDoor(){}

void OneWayDoor::setEntrance(){
    Entrance = true;
}

void OneWayDoor::setExit(){
    Exit = true;
}

std::string OneWayDoor::description(){
    if (OneWayDoor::isEntrance()){
        return "The Entrance ";
    }
    else if (OneWayDoor::isExit()) {
        return "The Exit ";
    }
    else {
        return "An One-way Door ";
    }
}
