#include "dungeonlevelbuilder.h"

using core::creatures::Monster;
using core::items::Weapon;
using core::items::Consumable;
using core::dungeon::Room;
using core::dungeon::DungeonLevel;
using core::dungeon::DungeonLevelBuilder;

DungeonLevelBuilder::DungeonLevelBuilder(){
    aMonster = new Monster();
    aWeapon = new Weapon();
    aConsumable = new Consumable();
}

DungeonLevelBuilder::~DungeonLevelBuilder(){
    delete aMonster;
    delete aWeapon;
    delete aConsumable;
    delete _Dungeonlevel;
}


/*
 * buildungeonLevel, buildRoom, builDoorway, buildEntrance,
 * buildExit, buildItem, buildCreature is virtual function
 * So, they will be override in BasicDungeonLevelBuilder and
 * MagicalDungeonLevelBuilder. In this class, they could be empty
 */
void DungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
}

std::shared_ptr<Room> DungeonLevelBuilder::buildRoom(int id)
{
}

void DungeonLevelBuilder::builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                      Room::Direction direction, DungeonLevelBuilder::MoveConstraints constraints)
{
}

void DungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction)
{
}

void DungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction)
{
}

void DungeonLevelBuilder::buildItem(std::shared_ptr<Room> room)
{
}

void DungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room)
{
}


/*
 * Function getDungeonLevel uses to get the result or
 * product after building in builder design
 */
DungeonLevel *DungeonLevelBuilder::getDungeonLevel()
{
    return _Dungeonlevel;
}


/*
 * Function getOppositeDirection uses to return the the opposite
 * direction depending on current direction in @param direction
 */
Room::Direction DungeonLevelBuilder::getOppositeDirection(Room::Direction direction)
{
    if (direction == Room::Direction::North){
        return Room::Direction::South;
    }
    else if (direction == Room::Direction::South) {
        return Room::Direction::North;
    }
    else if (direction == Room::Direction::West) {
        return Room::Direction::East;
    }
    else{
        return Room::Direction::West;
    }
}


/*
 * Function randomDouble is put in DungeonLevelBuilder to
 * both BasicDungeonLevelBuilder and MagicalDungeonLevelBuider
 * could inherit and use in their class
 */
double DungeonLevelBuilder::randomDouble()
{
    return _realDistribution(_randomGenerator);
}



