#include "onewaydoor.h"

using core::dungeon::Doorway;
using core::dungeon::common::OneWayDoor;

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

char OneWayDoor::displayCharacter(Room::Direction direction)
{
    if (Entrance){
        return 'I';
    }
    else if (Exit) {
        return 'O';
    }
    else {
        if(direction == Room::Direction::North){
            return '^';
        }
        else if(direction == Room::Direction::South){
            return 'v';
        }
        else if(direction == Room::Direction::East){
            return '>';
        }
        else {
            return '<';
        }
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


