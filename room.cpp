#include "room.h"
#include<vector>

std::vector<Room> Iroom(16);


Room::Room(int id): _id{id}
{

}

Room::~Room(){}


int Room::id(){
    return _id;
}
