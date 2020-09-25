#include "basicdungeonlevelbuilder.h"

using core::dungeon::Room;
using core::dungeon::common::OpenDoorWay;
using core::dungeon::common::OneWayDoor;
using core::dungeon::common::LockedDoor;
using core::dungeon::common::BlockedDoorWay;
using core::dungeon::basic::BasicDungeonLevelBuilder;


BasicDungeonLevelBuilder::BasicDungeonLevelBuilder()
{
}


/*
 * Destructor BasicDungeonLevelBuilder is used to
 * to delete some used pointer in this class.
 */
BasicDungeonLevelBuilder::~BasicDungeonLevelBuilder(){
    delete _wall;
    delete _door;
    delete _oppositeDoor;
}


/*
 * Function buildungeonLevel is used to create new object of BasicDungeonLevel
 * Parameter will transfer into new object
 * @param name, width, height are name of dungeon, number of columns and
 * number of rows, respectively
 */
void BasicDungeonLevelBuilder::buildungeonLevel(std::string name,int width, int height)
{
     _Dungeonlevel = new BasicDungeonLevel(name, width, height);
}


/*
 * Function buildRoom is used to build a room with specific id
 * This room can be QuartzChamber(50%) or RockChamber(50%)
 * When create new room, wall object will be add into 4 edges of
 * room before build doorway, entrance or exit
 * @param id is id of room required to create
 */
std::shared_ptr<Room> BasicDungeonLevelBuilder::buildRoom(int id){
    //create pointer for new room to access edges
    std::shared_ptr<Room> Aroom;
    //Toss a coin to choose room type
    if (randomDouble() <= 3){
         Aroom = std::make_shared<QuartzChamber>(id);
    }
    else {
        Aroom = std::make_shared<RockChamber>(id);
    }

    //Build walls and add to 4 edges and then return room
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


/*
 * Function builDoorway is used to create specific doorway from one room
 * to other room. In this function, 2 new doorway object will be created,
 * make connection and add to the edge of origin room and destination depending
 * on its direction
 * @param origin is the room need to build doorway
 * @param destination is the room doorway will go to
 * @param direction is the direction of origin having doorway
 * @param constraints is used to recognize what type of doorway will build
 */
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


/*
 * Function buildEntrance is used to create a entrance in anyroom.
 * A onewaydoor object will be required to create, then change it become
 * a entrance instead of onewaydoor and add it to the room depending
 * on direction.
 * @param room is the room will have Entrance at @param direction
 */
void BasicDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction){
    _door = new OneWayDoor();
    _door->setEntrance();
    room->setEdge(_door,direction);
}


/*
 * Function buildExit is used to create a exit in anyroom.
 * A onewaydoor object will be required to create, then change it become
 * a entrance instead of onewaydoor and add it to the room depending
 * on direction.
 * @param room is the room will have buildExit at @param direction
 */
void BasicDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction){
    _door = new OneWayDoor();
    _door->setExit();
    room->setEdge(_door,direction);
}


/*
 * Function buildItem uses to create item randomly in a room
 * There is 65% chance that the Item is a Consumable and a 35% chance that it is a Weapon.
 * Random number range is 0.0 to 6.0
 * So, when random number < 6*35% = 2.1, weapon will appear in this room
 * And the remaining random number will respond consumable
 * Only a weapon or a consumable can appear in a room
 * Object will be set name to recognize types and be added the clone
 * if it into room
 * @param room is the room will have Item
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
 * Function buildCreature uses to create monster randomly in a room
 * Only one monster can appear in a room
 * The room have monster and exit will contain boss
 * After set monster become boss, clone and add it to room, it need
 * to convert to normal boss to make sure clone of object will
 * be a normal monster in other room
 * There is 1/3 chance to appear a type of monster
 * @param room is the room will have monster
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

