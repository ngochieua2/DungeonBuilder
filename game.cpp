#include "game.h"
//#include<string>

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


}

