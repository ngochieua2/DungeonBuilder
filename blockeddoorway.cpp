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
    if(_oppositeDoor->isOneWayDoor()){
        if(direction == Room::Direction::North){
            return _oppositeDoor->displayCharacter(Room::Direction::South);
        }
        if(direction == Room::Direction::South){
            return _oppositeDoor->displayCharacter(Room::Direction::North);
        }
        if(direction == Room::Direction::East){
            return _oppositeDoor->displayCharacter(Room::Direction::West);
        }
        else{
            return _oppositeDoor->displayCharacter(Room::Direction::East);
        }

    }
    else{
        return 'X';
    }
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
