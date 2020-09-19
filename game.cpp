#include "game.h"
//#include<string>

using core::Game;

Game::Game(){}

Game::~Game(){};

void Game::setDungeonType(DungeonLevelBuilder *builder, std::string type){
    if (type == "basic"){
        builder = new BasicDungeonLevelBuilder();
    }
}

void Game::createExampleLevel(){
    setDungeonType(_builder, "basic");
    _builder->buildungeonLevel("Example Dungeon Level", 3 , 3);

    dungeon = _builder->getDungeonLevel();

}

DungeonLevel Game::getDungeon(){
    return *dungeon;
}
