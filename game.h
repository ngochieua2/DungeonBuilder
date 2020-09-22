#ifndef GAME_H
#define GAME_H
#include<basicdungeonlevelbuilder.h>
#include<basicdungeonlevel.h>
#include<string>

namespace core
{

class Game
{
public:
    static Game* getInstance(){
        if (theInstance == nullptr){
            theInstance = new Game;
        }
        return theInstance;
    }


    void setDungeonType(std::string type);
    void createExampleLevel();
    //createRandomLevel(std::string name, int width, int height)
    //displayLevel()
    //double randomDouble()

    Game(Game const&) = delete;
    void operator = (Game const&) = delete;


    core::dungeon::DungeonLevel* getDungeon();


private:
    static Game* theInstance;
    Game();
    ~Game();
    core::dungeon::DungeonLevelBuilder *_builder;

    core::dungeon::DungeonLevel *dungeon;

};

}
#endif // GAME_H
