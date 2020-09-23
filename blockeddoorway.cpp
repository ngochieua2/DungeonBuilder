#include "blockeddoorway.h"

using core::dungeon::Doorway;
using core::dungeon::common::BlockedDoorWay;

BlockedDoorWay::BlockedDoorWay(){}

BlockedDoorWay::~BlockedDoorWay(){}

std::string BlockedDoorWay::description(){
    return "a Block Door ";
}

char BlockedDoorWay::displayCharacter()
{
    if(_oppositeDoor->isOneWayDoor()){
        return _oppositeDoor->displayCharacter();
    }
    else {
        return 'X';
    }
}



void BlockedDoorWay::setEntrance(){
    Entrance = false;
}

void BlockedDoorWay::setExit(){
    Exit = false;
}
