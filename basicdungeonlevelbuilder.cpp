#include "basicdungeonlevelbuilder.h"

using core::dungeon::Room;
using core::dungeon::common::OpenDoorWay;
using core::dungeon::common::OneWayDoor;
using core::dungeon::common::LockedDoor;
using core::dungeon::common::BlockedDoorWay;
using core::dungeon::basic::BasicDungeonLevelBuilder;

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder(){}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder(){
    delete _wall;
    delete _door;
    delete _oppositeDoor;
}


void BasicDungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
     _Dungeonlevel = new BasicDungeonLevel(name, width, height);
}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    //create pointer for new room to access edges // May need to optimate
    std::shared_ptr<Room> Aroom;
    //Toss a coin to choose room type
    if (randomDouble() <= 3){
         Aroom = std::make_shared<QuartzChamber>(id);
    }
    else {
        Aroom = std::make_shared<RockChamber>(id);
    }

    //Build walls and add to 4 edges
    _wall = new RockWall();
    Aroom->setEdge(_wall, Room::Direction::North);
    _wall = new RockWall();
    Aroom->setEdge(_wall, Room::Direction::East);
    _wall = new RockWall();
    Aroom->setEdge(_wall, Room::Direction::South);
    _wall = new RockWall();
    Aroom->setEdge(_wall, Room::Direction::West);

    return Aroom;

}

void BasicDungeonLevelBuilder::builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                           Room::Direction direction, MoveConstraints constraints){

    //condition and build an opendoorway
    if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _door = new OpenDoorWay();
        _oppositeDoor = new OpenDoorWay();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    //condition and build an onewaydoor from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::DestinationImpassable))){
        _door = new OneWayDoor();
        _oppositeDoor = new BlockedDoorWay();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    //condition and build an onewaydoor from destination to origin
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _door = new BlockedDoorWay();
        _oppositeDoor = new OneWayDoor();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    //condition and build an blockedDoorway from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)|
                                     static_cast<unsigned>(MoveConstraints::DestinationImpassable))){
        _door = new BlockedDoorWay();
        _oppositeDoor = new BlockedDoorWay();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    //condition and build an lockedDoorway from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)|
                                     static_cast<unsigned>(MoveConstraints::DestinationLocked))){
        _door = new LockedDoor();
        _oppositeDoor = new LockedDoor();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    //condition and build an one way doorway in origin and a locked doorway in destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::DestinationLocked))){
        _door = new OneWayDoor();
        _oppositeDoor = new LockedDoor();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    //condition and build a locked door in origin and an one way door in destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _door = new LockedDoor();
        _oppositeDoor = new OneWayDoor();
        _door->connect(_oppositeDoor);
        _oppositeDoor->connect(_door);
        origin->setEdge(_door,direction);
        destination->setEdge(_oppositeDoor, getOppositeDirection(direction));

    }
    else{
        //Do nothing
    }
}

void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){
    _door = new OneWayDoor();
    _door->setEntrance();
    room->setEdge(_door,direction);
}

void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    _door = new OneWayDoor();
    _door->setExit();
    room->setEdge(_door,direction);
}

/*
 * there is 65% chance that the Item is a Consumable and a 35% chance that it is a Weapon.
 * Random number range is 0.0 to 6.0
 * So, when random number < 6*35% = 2.1, weapon will appear in this room
 * And the remaining random number will respond consumable
 * Only a weapon or a consumable can appear in a room
 */

void BasicDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room)
{
    double value{0};

    if (randomDouble() <= 2.1)
    /*
     * A weapon may appears in this room, including:
     * - Boomerang
     * - Short Sword
     * - Battle Axe
     */
    {
        value = randomDouble();
        if(value <= 2) // a boomerang appears in the room (2/6 = 1/3 chance)
        {
            aWeapon->setName("Boomerang");
            room->setItem(aWeapon->clone());
        }
        else if (value <= 4) // a Short Sword appears in the room (1/3 chance)
        {
            aWeapon->setName("Short Sword");
            room->setItem(aWeapon->clone());
        }
        else // a Battle Axe appears in the room (1/3 chance)
        {
            aWeapon->setName("Battle Axe");
            room->setItem(aWeapon->clone());
        }
    }
    else
    /*
     * A consumable may appears in this room, including:
     * - Health Potion
     * - Molotov Cocktail
     * - Smoke Bomb
     */
    {
        value = randomDouble();
        if(value <= 2) // a Health Potion appears in the room (2/6 = 1/3 chance)
        {
            aConsumable->setName("Health Potion");
            room->setItem(aConsumable->clone());
        }
        else if (value <= 4) // a Molotov Cocktail appears in the room (1/3 chance)
        {
            aConsumable->setName("Molotov Cocktail");
            room->setItem(aConsumable->clone());
        }
        else // a Smoke Bomb appears in the room (1/3 chance)
        {
            aConsumable->setName("Smoke Bomb");
            room->setItem(aConsumable->clone());
        }
    }

}

/*
 * Only one monster can appear in a room
 * The room with exit, if monster appear on it,
 * it will be a boss, so it is necessary to check having a exit or not
 */


void BasicDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room)
{
    //set boss if this room has exit
    if (room->hasExit())
    {
        aMonster->setBoss(true);
    }

    /*
     * There are three monsters type in Basic dungeon level
     * - Goblin
     * - Werewolf
     * - Evil Wizard
     */
    double value{0};
    value = randomDouble();
    if (value <= 2) //Goblin appears in the room (2/6 = 1/3 chance)
    {
        aMonster->setName("Goblin");
        room->setCreature(aMonster->clone());
    }
    else if (value <= 4) // Werewolf appears in the room (1/3 chance)
    {
        aMonster->setName("Werewolf");
        room->setCreature(aMonster->clone());
    }
    else // Evil Wizard appears in the room (1/3 chance)
    {
        aMonster->setName("Evil Wizard");
        room->setCreature(aMonster->clone());
    }
    aMonster->setBoss(false);
}

