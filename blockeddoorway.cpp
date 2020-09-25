#include "blockeddoorway.h"

using core::dungeon::Doorway;
using core::dungeon::common::BlockedDoorWay;

BlockedDoorWay::BlockedDoorWay()
{
}

BlockedDoorWay::~BlockedDoorWay()
{
}

std::string BlockedDoorWay::description(){
    return "a Block Door ";
}


/*
 * Function displayCharacter use to print correct character
 * It will need to check the opposite doorway is onewaydoor
 * or not. if yes, it will print character of onewaydoor
 * if no, print character of blockedDoorway
 */
char BlockedDoorWay::displayCharacter()
{
    if(_oppositeDoor->isOneway()){
        return _oppositeDoor->displayCharacter();
    }
    else {
        return 'X';
    }
}


/*
 * if it is BlockedDoorway, it will not entrance or exit
 */
void BlockedDoorWay::setEntrance(){
    Entrance = false;
}
void BlockedDoorWay::setExit(){
    Exit = false;
}
