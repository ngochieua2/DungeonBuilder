#include "opendoorway.h"

using core::dungeon::Doorway;
using core::dungeon::common::OpenDoorWay;

OpenDoorWay::OpenDoorWay(){}

OpenDoorWay::~OpenDoorWay(){}


std::string OpenDoorWay::description(){
    return "an Open Door to another chamber";
}

char OpenDoorWay::displayCharacter(Room::Direction direction)
{
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
