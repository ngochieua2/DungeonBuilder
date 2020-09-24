#ifndef GAME_H
#define GAME_H
#include<basicdungeonlevelbuilder.h>
#include<basicdungeonlevel.h>
#include<string>
#include <random>
#include <ctime>
#include <ostream>

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

    void displayLevel(std::ostream &display);

    double randomDouble();

    Game(Game const&) = delete;
    void operator = (Game const&) = delete;


    core::dungeon::DungeonLevel* getDungeon();


private:
    static Game* theInstance;
    Game();
    ~Game();
    core::dungeon::DungeonLevelBuilder *_builder;

    core::dungeon::DungeonLevel *dungeon;

    std::mt19937 _randomGenerator{uint32_t(time(nullptr))}; //!< Mersenne Twister random number generator seeded by current time
    std::uniform_real_distribution<double> _realDistribution{0.0, 100.0}; //!< For random numbers between 0.0 & 100.0
};

}
#endif // GAME_H
