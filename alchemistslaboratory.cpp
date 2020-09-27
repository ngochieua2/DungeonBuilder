#include "alchemistslaboratory.h"

using core::dungeon::magical::AlchemistsLaboratory;



AlchemistsLaboratory::AlchemistsLaboratory(int id)
{
    _id = id;
    EdgesVector.assign(4,_roomEdge);
}


AlchemistsLaboratory::~AlchemistsLaboratory(){
    delete _roomEdge;
    for (int i = 0; i < (int)EdgesVector.size(); ++ i){
        delete EdgesVector[i];
    }
}


std::string AlchemistsLaboratory::description(){
    return "A Laboratory with many toxic chemistry and strange creatures. (Alchemists Laboratory)\n"
           "To the NORTH is " + edgeDescription(Direction::North)+ "\n"
           "To the SOUTH is " + edgeDescription(Direction::South)+ "\n"
           "To the EAST is " + edgeDescription(Direction::East)+ "\n"
           "To the WEST is " + edgeDescription(Direction::West)+ "\n"
           + creatureDescription() + itemDescription() + "\n";
}
