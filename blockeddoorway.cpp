#include "blockeddoorway.h"

BlockedDoorWay::BlockedDoorWay()
{

}

char BlockedDoorWay::Doorway::RoomEdge::displayCharacter(Room::Direction type){
    return 'X';
}
