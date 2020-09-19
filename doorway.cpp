#include "doorway.h"

Doorway::Doorway(){}

Doorway::~Doorway(){
    delete [] _doorway;
}

std::string Doorway::description()
{
    return "doorway ";
}

void Doorway::connect (Doorway *opposite){
    _doorway = opposite;
}

Doorway* Doorway::getOpposite(){
    return _doorway;
}

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

Doorway::DoorwayType Doorway::getDoorwayType(){
    return DoorwayType::Undefine;
}
