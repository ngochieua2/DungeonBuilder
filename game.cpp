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
    //setDungeonType("basic");
    _builder = new BasicDungeonLevelBuilder();
    _builder->buildungeonLevel("Example Dungeon Level", 1 , 1);

    dungeon = _builder->getDungeonLevel();

}

DungeonLevel* Game::getDungeon(){
    return dungeon;
}
