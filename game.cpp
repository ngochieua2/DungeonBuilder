#include "game.h"
//#include<string>

Game::Game(){}

Game::~Game(){};

void Game::setDungeonType(DungeonLevelBuilder *builder, std::string type){
    if(type == "basic"){
        builder = new BasicDungeonLevelBuilder();
    }
    if (type == "Magic"){

    }
}

void Game::createExampleLevel(){
    setDungeonType(_builder,"basic");
    _builder->buildungeonLevel("example", 3 , 3 );
    for (int i = 0; _builder->getDungeonLevel()->numberOfRooms();i++){
        _builder->buildRoom(i+1);

    }




}
