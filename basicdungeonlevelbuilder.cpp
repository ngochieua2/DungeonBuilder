#include "basicdungeonlevelbuilder.h"

using core::dungeon::Room;
using core::dungeon::common::OpenDoorWay;
using core::dungeon::common::OneWayDoor;
using core::dungeon::common::LockedDoor;
using core::dungeon::common::BlockedDoorWay;
using core::dungeon::basic::BasicDungeonLevelBuilder;

BasicDungeonLevelBuilder::BasicDungeonLevelBuilder(){}

BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder(){
    delete[] _edge;
    //delete[] _wall;
    //delete[] _door;
}


void BasicDungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
     _Dungeonlevel = new BasicDungeonLevel(name, width, height);
}

std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    //create pointer for new room to access edges // May need to optimate
    std::shared_ptr<Room> Aroom;
    //Toss a coin to choose room type
    if (randomDouble() <= 2){
         Aroom = std::make_shared<QuartzChamber>(id);
    }
    else {
        Aroom = std::make_shared<RockChamber>(id);
    }

    //Build walls and add to 4 edges
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::North);
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::East);
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::South);
    _edge = new RockWall();
    Aroom->setEdge(_edge, Room::Direction::West);

    return Aroom;

}

void BasicDungeonLevelBuilder::builDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                           Room::Direction direction, MoveConstraints constraints){

    //condition and build an opendoorway
    if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _edge = new core::dungeon::common::OpenDoorWay();
        origin->setEdge(_edge,direction);
        //destination->edgeAt(getOppositeDirection(direction))
        //set connect
        _edge = new OpenDoorWay();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an onewaydoor from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::DestinationImpassable))){
        _edge = new OneWayDoor();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new BlockedDoorWay();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an onewaydoor from destination to origin
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _edge = new BlockedDoorWay();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new OneWayDoor();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an blockedDoorway from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginImpassable)|
                                     static_cast<unsigned>(MoveConstraints::DestinationImpassable))){
        _edge = new BlockedDoorWay();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new BlockedDoorWay();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an lockedDoorway from origin to destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)|
                                     static_cast<unsigned>(MoveConstraints::DestinationLocked))){
        _edge = new LockedDoor();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new LockedDoor();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build an one way doorway in origin and a locked doorway in destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::None)|
                                     static_cast<unsigned>(MoveConstraints::DestinationLocked))){
        _edge = new OneWayDoor();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new LockedDoor();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    //condition and build a locked door in origin and an one way door in destination
    else if (constraints == static_cast<MoveConstraints>(static_cast<unsigned>(MoveConstraints::OriginLocked)|
                                     static_cast<unsigned>(MoveConstraints::None))){
        _edge = new LockedDoor();
        origin->setEdge(_edge,direction);
        //set connect
        _edge = new OneWayDoor();
        destination->setEdge(_edge, getOppositeDirection(direction));

    }
    else{
        //Do nothing
    }
}

void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){
    _edge = new OneWayDoor();
    _edge->setEntrance();
    room->setEdge(_edge,direction);
}

void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    _edge = new OneWayDoor();
    _edge->setExit();
    room->setEdge(_edge,direction);
}

void BasicDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room)
{
    /*
     * Only a weapon or a consumable can appear in a room
     */
    double value{0};

    if (randomDouble() <= 2)
    /*
     * A weapon may appears in this room, including:
     * - Boomerang
     * - Short Sword
     * - Battle Axe
     */
    {
        value = randomDouble();
        if(value <= 1) // a boomerang appears in the room
        {
            aWeapon->setName("Boomerang");
            room->setItem(aWeapon->clone());
        }
        else if (value <= 2) // a Short Sword appears in the room
        {
            aWeapon->setName("Short Sword");
            room->setItem(aWeapon->clone());
        }
        else if (value <= 3) // a Battle Axe appears in the room
        {
            aWeapon->setName("Battle Axe");
            room->setItem(aWeapon->clone());
        }
        else //No weapon in the room
        {
            room->setItem(nullptr);
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
        if(value <= 1) // a Health Potion appears in the room
        {
            aConsumable->setName("Health Potion");
            room->setItem(aConsumable->clone());
        }
        else if (value <= 2) // a Molotov Cocktail appears in the room
        {
            aConsumable->setName("Molotov Cocktail");
            room->setItem(aConsumable->clone());
        }
        else if (value <= 3) // a Smoke Bomb appears in the room
        {
            aConsumable->setName("Smoke Bomb");
            room->setItem(aConsumable->clone());
        }
        else //No consumable in the room
        {
            room->setItem(nullptr);
        }
    }

}

void BasicDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room)
{
    //set boss if this room has exit
    if (room->edgeAt(Room::Direction::North)->isExit() ||
        room->edgeAt(Room::Direction::South)->isExit() ||
        room->edgeAt(Room::Direction::East)->isExit() ||
        room->edgeAt(Room::Direction::West)->isExit())
    {
        aMonster->setBoss();
    }


    /*
     * Only one monster can appear in a room
     * There are three monsters type in Basic dungeon level
     * - Goblin
     * - Werewolf
     * - Evil Wizard
     */
    double value{0};
    value = randomDouble();
    if (value <= 1) //Goblin appears in the room
    {
        aMonster->setName("Goblin");
        room->setCreature(aMonster->clone());
    }
    else if (value <= 2) // Werewolf appears in the room
    {
        aMonster->setName("Werewolf");
        room->setCreature(aMonster->clone());
    }
    else if (value <= 3) // Evil Wizard appears in the room
    {
        aMonster->setName("Evil Wizard");
        room->setCreature(aMonster->clone());
    }
    else // No monster in this room
    {
        room->setCreature(nullptr);
    }

}

