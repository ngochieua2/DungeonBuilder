#include "doorway.h"

Doorway::Doorway()
{

}

Doorway::~Doorway(){}

void Doorway::connect (Doorway *opposite){

}

bool Doorway::isEntrance(){}

bool Doorway::isExit(){}


bool Doorway::isPassage(){
//    if(isEntrance() || isExit()){
//        return false;
//    }
    return true;
}
