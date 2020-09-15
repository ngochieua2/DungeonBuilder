#include "onewaydoor.h"

OneWayDoor::OneWayDoor()
{

}

bool OneWayDoor::Doorway::isEntrance(){return true;}

bool OneWayDoor::Doorway::isExit(){return true;}

char OneWayDoor::Doorway::RoomEdge::displayCharacter(Room::Direction type){
    if (type == Room::Direction::North) return 'v';
    else if (type == Room::Direction::West) return '<';
    else if (type == Room::Direction::South) return '^';
    else return '>';
}
