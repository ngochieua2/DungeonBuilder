#include "opendoorway.h"

OpenDoorWay::OpenDoorWay(){}

OpenDoorWay::~OpenDoorWay(){}


std::string OpenDoorWay::description(){
    return "A Open Door ";
}

void OpenDoorWay::setEntrance(){
    Entrance = false;
}

void OpenDoorWay::setExit(){
    Exit = false;
}
