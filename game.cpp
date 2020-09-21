#include "game.h"
//#include<string>

using core::Game;

Game::Game(){
}

Game::~Game(){
    delete _builder;
    delete dungeon;
};

void Game::setDungeonType(std::string type){
    if (type == "basic"){
        _builder = new BasicDungeonLevelBuilder();
    }
}

void Game::createExampleLevel(){
    setDungeonType("basic");
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


}

DungeonLevel* Game::getDungeon(){
    return dungeon;
}
