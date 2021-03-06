#include "rockchamber.h"

using core::dungeon::basic::RockChamber;

RockChamber::RockChamber(int id)
{
    _id = id;
    EdgesVector.assign(4,_roomEdge);
}

RockChamber::~RockChamber()
{
    delete _roomEdge;
    for (int i = 0; i < (int)EdgesVector.size(); ++ i){
        delete EdgesVector[i];
    }
}

std::string RockChamber::description(){
    return "A chamber is dark and supper cold. (Rock Chamber)\n"
           "To the NORTH is " + edgeDescription(Direction::North)+ "\n"
           "To the SOUTH is " + edgeDescription(Direction::South)+ "\n"
           "To the EAST is " + edgeDescription(Direction::East)+ "\n"
           "To the WEST is " + edgeDescription(Direction::West)+ "\n"
           + creatureDescription() + itemDescription() + "\n";
}
