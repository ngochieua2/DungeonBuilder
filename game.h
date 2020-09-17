#ifndef GAME_H
#define GAME_H

#include<dungeonlevelbuilder.h>
#include<basicdungeonlevelbuilder.h>
#include<basicdungeonlevel.h>
//#include<dungeonlevel.h>
#include<string>

class Game
{
public:
    static Game* getInstance(){
        if (theInstance == nullptr){
            theInstance = new Game;
        }
        return theInstance;
    }


    void setDungeonType(DungeonLevelBuilder *builder, std::string type);
    void createExampleLevel();
    //createRandomLevel(std::string name, int width, int height)
    //displayLevel()
    //double randomDouble()

    Game(Game const&) = delete;
    void operator = (Game const&) = delete;


    DungeonLevel getDungeon();


private:
    static Game* theInstance;
    Game();
    ~Game();
    DungeonLevelBuilder *_builder;

    DungeonLevel *dungeon;

};

#endif // GAME_H
