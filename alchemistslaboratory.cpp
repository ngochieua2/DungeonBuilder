#include "alchemistslaboratory.h"

using core::dungeon::magical::AlchemistsLaboratory;

/*
 * Constructor AlchemistsLaboratory is used to store id of created room
 * and create default vector of room edges, there are four directions(south, east,
 * north, east), so need to assign 4 first values in vector
 */

AlchemistsLaboratory::AlchemistsLaboratory(int id)
{
    _id = id;
    EdgesVector.assign(4,_roomEdge);
}

/*
 * Destructor AlchemistsLaboratory is used to delete null pointer _roomedge
 * and delete all members of EdgesVector
 */
AlchemistsLaboratory::~AlchemistsLaboratory(){
    delete _roomEdge;
    for (int i = 0; i < (int)EdgesVector.size(); ++ i){
        delete EdgesVector[i];
    }
}

/*
 * Function description uses to describe details of the room
 * include in 4 edges and monster and items
 */
std::string AlchemistsLaboratory::description(){
    return "A Laboratory with many toxic chemistry and strange creatures. (Alchemists Laboratory)\n"
           "To the NORTH is " + edgeDescription(Direction::North)+ "\n"
           "To the SOUTH is " + edgeDescription(Direction::South)+ "\n"
           "To the EAST is " + edgeDescription(Direction::East)+ "\n"
           "To the WEST is " + edgeDescription(Direction::West)+ "\n"
           + creatureDescription() + itemDescription() + "\n";
}
