#include "doorway.h"

using core::dungeon::Doorway;

Doorway::Doorway(){}

Doorway::~Doorway(){
    delete _oppositeDoor;
}

std::string Doorway::description()
{
    return "doorway ";
}

char Doorway::displayCharacter()
{
    return character;
}

/*
 * Function connect use to store infor of
 * the door in opposite it connects with
 * With entrance and exit, they will not connect
 * with anything, so their opposite will be nullptr
 * @param opposite is poiner of the door connect with
 */
void Doorway::connect (Doorway *opposite){
    _oppositeDoor = opposite;
}


bool Doorway::isEntrance(){
    return Entrance;
}

bool Doorway::isExit(){
    return Exit;
}

void Doorway::setEntrance()
{
}

void Doorway::setExit()
{
}

bool Doorway::isOneway()
{
    return oneway;
}

/*
 * Function isPassage is used to distinguish wall,
 * entrance, exit (false) or a normal doorway (true)
 */

bool Doorway::isPassage(){
    if(isEntrance() || isExit()){
        return false;
    }
    else {
        return true;
    }

}
