#include "doorway.h"

Doorway::Doorway(){}

Doorway::~Doorway(){}

void Doorway::connect (Doorway *opposite){}

bool Doorway::isEntrance(){
    return Entrance;
}

bool Doorway::isExit(){
    return Exit;
}

void Doorway::setEntrance(){}

void Doorway::setExit(){}


bool Doorway::isPassage(){
    if(isEntrance() || isExit()){
        return false;
    }
    return true;
}
