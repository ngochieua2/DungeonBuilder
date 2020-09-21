#include "rockchamber.h"


RockChamber::RockChamber(int id)
{
    _id = id;
    EdgesVector.assign(4,_roomEdge);
}

RockChamber::~RockChamber(){}

std::string RockChamber::description(){
    return "A chamber that glitters like a thousand stars in the tourch light. (Rock Chamber)\n"
           "To the NORTH is " + edgeDescription(Direction::North)+ "\n"
           "To the SOUTH is " + edgeDescription(Direction::South)+ "\n"
           "To the EAST is " + edgeDescription(Direction::East)+ "\n"
           "To the WEST is " + edgeDescription(Direction::West)+ "\n";
}
