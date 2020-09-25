#include "opendoorway.h"

using core::dungeon::Doorway;
using core::dungeon::common::OpenDoorWay;

OpenDoorWay::OpenDoorWay()
{}

OpenDoorWay::~OpenDoorWay()
{
}


std::string OpenDoorWay::description(){
    return "an Open Door to another chamber";
}


void OpenDoorWay::setEntrance(){
    Entrance = false;
}

void OpenDoorWay::setExit(){
    Exit = false;
}

