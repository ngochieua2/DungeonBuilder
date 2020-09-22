#include "doorway.h"

using core::dungeon::Doorway;

Doorway::Doorway(){}

Doorway::~Doorway(){
    delete [] _doorway;
}

std::string Doorway::description()
{
    return "doorway ";
}

char Doorway::displayCharacter(Room::Direction direction)
{
    return 'd';
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
    else {
        return true;
    }

}

Doorway::DoorwayType Doorway::getDoorwayType(){
    return DoorwayType::Undefine;
}
