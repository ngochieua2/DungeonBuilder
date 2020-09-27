#include "roomedge.h"

using core::dungeon::RoomEdge;
using core::dungeon::Room;

RoomEdge::RoomEdge()
{
}

RoomEdge::~RoomEdge()
{
}

std::string RoomEdge::description()
{
    return "roomedge ";
}

void RoomEdge::setChar(char sChar)
{
    character = sChar;
}

char RoomEdge::displayCharacter()
{
    return character;
}


bool RoomEdge::isPassage(){
    return false;
}

bool RoomEdge::isEntrance(){
    return Entrance;
}

bool RoomEdge::isExit()
{
    return Exit;
}

void RoomEdge::setEntrance()
{
}

void RoomEdge::setExit()
{
}





