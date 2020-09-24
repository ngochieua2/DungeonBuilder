#include "doorway.h"

using core::dungeon::Doorway;

Doorway::Doorway(){}

Doorway::~Doorway(){
    delete [] _oppositeDoor;
}

std::string Doorway::description()
{
    return "doorway ";
}

char Doorway::displayCharacter()
{
    return character;
}


void Doorway::connect (Doorway *opposite){
    _oppositeDoor = opposite;
}


bool Doorway::isEntrance(){
    return Entrance;
}

bool Doorway::isExit(){
    return Exit;
}

void Doorway::setEntrance(){}

void Doorway::setExit(){}

bool Doorway::isOneway()
{
    return oneway;
}


bool Doorway::isPassage(){
    if(isEntrance() || isExit()){
        return false;
    }
    else {
        return true;
    }

}
