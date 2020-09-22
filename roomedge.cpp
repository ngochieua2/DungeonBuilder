#include "roomedge.h"

using core::dungeon::RoomEdge;

RoomEdge::RoomEdge(){}

RoomEdge::~RoomEdge(){}

std::string RoomEdge::description()
{
    return "roomedge ";
}

char RoomEdge::displayCharacter(){
    return '?';
}

bool RoomEdge::isPassage(){
    return false;
}

bool RoomEdge::isEntrance(){
    return false;
}

bool RoomEdge::isExit()
{
    return false;
}

void RoomEdge::setEntrance(){}

void RoomEdge::setExit(){}

RoomEdge::DoorwayType RoomEdge::getDoorwayType()
{
    return DoorwayType::Undefine;
}




