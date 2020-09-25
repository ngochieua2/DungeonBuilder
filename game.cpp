#include "game.h"
//#include<string>

using core::Game;
using core::dungeon::Room;
using core::dungeon::DungeonLevelBuilder;
using core::dungeon::DungeonLevel;
using core::dungeon::basic::BasicDungeonLevelBuilder;


Game::Game(){
}

Game::~Game(){
    delete _builder;
    delete dungeon;
};

void Game::setDungeonType(std::string type){
    if (type == "b"){
        _builder = new BasicDungeonLevelBuilder();
    }
}

void Game::createExampleLevel(){
    setDungeonType("b");
    _builder->buildungeonLevel("Example Dungeon Level", 3 , 3);
    dungeon = _builder->getDungeonLevel();

    //Build room by width and height
    for(int i = 0; i < dungeon->numberOfRooms(); ++i){
         dungeon->addRoom(_builder->buildRoom(i+1));
    }
    //Build an open doorway in the East of room 1 to the West of room 2
    _builder->builDoorway(dungeon->retrieveRoom(1),dungeon->retrieveRoom(2),
                          Room::Direction::East,static_cast<DungeonLevelBuilder::MoveConstraints>(0));
    //Build a block doorway in the East of room 2 and a block doorway in the West of room 3
    _builder->builDoorway(dungeon->retrieveRoom(2),dungeon->retrieveRoom(3),
                          Room::Direction::East,static_cast<DungeonLevelBuilder::MoveConstraints>(3));
    //Build an one way door in the South of room 1 to the North of room 4
    _builder->builDoorway(dungeon->retrieveRoom(1),dungeon->retrieveRoom(4),
                          Room::Direction::South,static_cast<DungeonLevelBuilder::MoveConstraints>(2));
    //Build an open doorway in the South of room 2 to the North of room 5
    _builder->builDoorway(dungeon->retrieveRoom(2),dungeon->retrieveRoom(5),
                          Room::Direction::South,static_cast<DungeonLevelBuilder::MoveConstraints>(0));
    //Build an one way door in the South of room 3 and locked door way in the North of room 6
    _builder->builDoorway(dungeon->retrieveRoom(3),dungeon->retrieveRoom(6),
                          Room::Direction::South,static_cast<DungeonLevelBuilder::MoveConstraints>(8));
    //Build an one way door in the East of room 4 to the West of room 5
    _builder->builDoorway(dungeon->retrieveRoom(4),dungeon->retrieveRoom(5),
                          Room::Direction::East,static_cast<DungeonLevelBuilder::MoveConstraints>(2));
    //Build an open doorway in the East of room 5 to the West of room 6
    _builder->builDoorway(dungeon->retrieveRoom(5),dungeon->retrieveRoom(6),
                          Room::Direction::East,static_cast<DungeonLevelBuilder::MoveConstraints>(0));
    //Build a blocked doorway in the South of room 4 and the North of room 7
    _builder->builDoorway(dungeon->retrieveRoom(4),dungeon->retrieveRoom(7),
                          Room::Direction::South,static_cast<DungeonLevelBuilder::MoveConstraints>(3));
    //Build an open way door in the South of room 5 and the North of room 8
    _builder->builDoorway(dungeon->retrieveRoom(5),dungeon->retrieveRoom(8),
                          Room::Direction::South,static_cast<DungeonLevelBuilder::MoveConstraints>(0));
    //Build a locked doorway in the East of room 7 and a locked doorway in the West of room 8
    _builder->builDoorway(dungeon->retrieveRoom(7),dungeon->retrieveRoom(8),
                          Room::Direction::East,static_cast<DungeonLevelBuilder::MoveConstraints>(12));
    //Build an open waydoor in the East of room 8 in the West of room 9
    _builder->builDoorway(dungeon->retrieveRoom(8),dungeon->retrieveRoom(9),
                          Room::Direction::East,static_cast<DungeonLevelBuilder::MoveConstraints>(0));

    //Build entrance in the North of room 1
    _builder->buildEntrance(dungeon->retrieveRoom(1),Room::Direction::North);
    //Build exit in the East of room 9
    _builder->buildExit(dungeon->retrieveRoom(9), Room::Direction::East);

    //Build creatures and items
    for(int i = 0; i < dungeon->numberOfRooms(); ++i){
        if (randomDouble() <= 60){
            _builder->buildCreature(dungeon->retrieveRoom(i+1));
        }
        if (randomDouble() <= 60){
            _builder->buildItem(dungeon->retrieveRoom(i+1));
        }
    }
}

int Game::randomDoorwayType()
{
    int randomValue = randomDouble();
    if(randomValue <= 30) // 30% chance that it is locked
    {
        if(randomValue <= 15) // 50 % chance to build a locked-locked doorway
        {
            return 12;
        }
        else // 50 % chance to build a locked - open doorway
        {
            return 4;
        }
    }
    else if (randomValue <= 60) // 30% chance that it is impassable
    {
        if(randomValue <= 45) // 50 % chance to build a blocked-open doorway
        {
            return 1;
        }
        else //50 % chance to build a blocked-blocked doorway
        {
            return 3;
        }
    }
    else //There is a 40% chance that an individual doorway is traversable
    {
        randomValue = randomDouble();
        if(randomValue <= (100/3)) // 33.33% chance to build open-open doorway
        {
            return 0;
        }
        else if (randomValue <= (100*2/3)) // 33.33% chance to build open-blocked doorway
        {
            return 2;
        }
        else // 33.33% chance to build open-locked doorway
        {
            return 8;
        }
    }
}

void Game::createRandomLevel(std::string name, int width, int height, std::string type)
{
    setDungeonType(type);
    _builder->buildungeonLevel(name, width , height);
    dungeon = _builder->getDungeonLevel();

    //random event

    if(dungeon->numberOfRooms() == 1) //event for 1x1 dungeon // special case
    {

    }
    else //event for the remaining 2x2, 3x3, 4x4 //normal case
    {
        //build room with the given width and height
        for (int i = 0; i < dungeon->numberOfRooms();++i){
            dungeon->addRoom(_builder->buildRoom(i+1));
        }

        int range = 2 + width;
        double randomValue{0};

        /*
         * Build entrance in the west of room 1 or the east of room *width*
         * or the north of room 1 to room *width*
         */
        for (int i = 1; i < range; ++i){
            if( i == (range - 1)){
                if(randomDouble() <= 50){
                    //build entrance in the west of room 1
                    _builder->buildEntrance(dungeon->retrieveRoom(1),Room::Direction::West);
                }
                else //build entrance in the East of room *width*
                {
                    _builder->buildEntrance(dungeon->retrieveRoom(width),Room::Direction::East);
                }
            }
            else if(randomDouble() <= 50){
                //build entrance in the north of first row and then break the loop
                _builder->buildEntrance(dungeon->retrieveRoom(i),Room::Direction::North);
                break;
            }
        }

        /*
         * Build exit in the East of room *widthxheight* or the West of room *widthxheight-width*
         * or the South of room *widthxheight-width* to room *widthxheight*
         */
        for (int i = 1; i < range; ++i){
            if( i == (range - 1)){
                if(randomDouble() <= 50){
                    //build exit in the west of first room of last row ((width*height)- width + 1)
                    _builder->buildExit(dungeon->retrieveRoom((width*height)- width + 1),Room::Direction::West);
                }
                else //build exit in the west of last room of last row (width*height)
                {
                    _builder->buildExit(dungeon->retrieveRoom(width*height),Room::Direction::East);
                }
            }
            else if(randomDouble() <= 50){
                //build exit in the south of last row and then break the loop
                _builder->buildExit(dungeon->retrieveRoom((width*height)- width + i),Room::Direction::South);
                break;
            }
        }

        /*
         * Build doorway
         * All room will need to check number of door before build new doorway
         */
        for(int i = 1; i <= width*height; ++i){
            if(i == 1) // west-north conner room
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 1) // build at least one doorway
                {
                    //build doorway at East
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+1),Room::Direction::East,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at south
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+width),Room::Direction::South,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i == width) // East-north conner room
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 1) // build at least one doorway
                {
                    //build doorway at West
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-1),Room::Direction::West,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at South
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+width),Room::Direction::South,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i == (width*height - width + 1)) // West-South conner room
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 1) // build at least one doorway
                {
                    //build doorway at East
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+1),Room::Direction::East,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at North
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-width),Room::Direction::North,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i == (width*height)) // East-South conner room
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 1) // build at least one doorway
                {
                    //build doorway at West
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-1),Room::Direction::West,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at North
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-width),Room::Direction::North,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i > 1 && i < width) // group of room in the North
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 2) // build at least two doorway
                {
                    //build doorway at West
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-1),Room::Direction::West,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at South
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+width),Room::Direction::South,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at East
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+1),Room::Direction::East,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i > width*height - width + 1 && i < width*height) // group of room in the South
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 2) // build at least two doorway
                {
                    //build doorway at West
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-1),Room::Direction::West,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at North
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-width),Room::Direction::North,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at East
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+1),Room::Direction::East,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i % width == 1) // group of room in the West
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 2) // build at least two doorway
                {
                    //build doorway at South
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+width),Room::Direction::South,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at North
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-width),Room::Direction::North,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at East
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+1),Room::Direction::East,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else if(i % width == 0) // group of room in the East
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 2) // build at least two doorway
                {
                    //build doorway at South
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+width),Room::Direction::South,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at North
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-width),Room::Direction::North,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at West
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-1),Room::Direction::West,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
            else // the remaining room
            {
                while (dungeon->retrieveRoom(i)->doorwayCount() < 2) // build at least two doorway
                {
                    //build doorway at South
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+width),Room::Direction::South,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at North
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-width),Room::Direction::North,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at West
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i-1),Room::Direction::West,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                    //build doorway at East
                    if(randomDouble() <= 50) //50% doorway will be build in this side
                    {
                        _builder->builDoorway(dungeon->retrieveRoom(i), dungeon->retrieveRoom(i+1),Room::Direction::East,
                                              static_cast<DungeonLevelBuilder::MoveConstraints>(randomDoorwayType()));
                    }
                }
            }
        }


        /*
         * Build monster and Item
         */


    }



}

void Game::displayLevel(std::ostream &display)
{
    display << dungeon->display();
}

double Game::randomDouble()
{
    return _realDistribution(_randomGenerator);
}

DungeonLevel* Game::getDungeon(){
    return dungeon;
}
