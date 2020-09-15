#include "lockeddoor.h"

LockedDoor::LockedDoor()
{

}

char LockedDoor::Doorway::RoomEdge::displayCharacter(Room::Direction type){
    return '@';
}
