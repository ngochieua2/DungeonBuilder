#include "quartzchamber.h"

using core::dungeon::basic::QuartzChamber;

QuartzChamber::QuartzChamber(int id)
{
    _id = id;
    EdgesVector.assign(4,_roomEdge);
}

QuartzChamber::~QuartzChamber(){
    delete _roomEdge;
    for (int i = 0; i < (int)EdgesVector.size(); ++ i){
        delete EdgesVector[i];
    }
}

std::string QuartzChamber::description(){
    return "A chamber that glitters like a thousand stars in the tourch light. (Quartz Chaber)\n"
           "To the NORTH is " + edgeDescription(Direction::North)+ "\n"
           "To the SOUTH is " + edgeDescription(Direction::South)+ "\n"
           "To the EAST is " + edgeDescription(Direction::East)+ "\n"
           "To the WEST is " + edgeDescription(Direction::West)+ "\n"
            + creatureDescription() + itemDescription() + "\n";
}
