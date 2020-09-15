#include "opendoorway.h"

OpenDoorWay::OpenDoorWay()
{

}

char OpenDoorWay::Doorway::RoomEdge::displayCharacter(Room::Direction type){
    if (type == Room::Direction::North) return '^';
    else if (type == Room::Direction::West) return '>';
    else if (type == Room::Direction::South) return 'v';
    else return '<';
}
