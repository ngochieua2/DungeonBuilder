#include "blockeddoorway.h"

using core::dungeon::Doorway;
using core::dungeon::common::BlockedDoorWay;

BlockedDoorWay::BlockedDoorWay(){
    character = 'X';
}

BlockedDoorWay::~BlockedDoorWay(){}

std::string BlockedDoorWay::description(){
    return "a Block Door ";
}

char BlockedDoorWay::displayCharacter()
{
    if(_oppositeDoor->isOneway()){
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
