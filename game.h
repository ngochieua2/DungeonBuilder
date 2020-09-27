#ifndef GAME_H
#define GAME_H
#include <basicdungeonlevelbuilder.h>
#include <basicdungeonlevel.h>
#include <magicaldungeonlevelbuilder.h>
#include <magicaldungeonlevel.h>
#include <string>
#include <random>
#include <ctime>
#include <ostream>

namespace core
{

class Game
{
public:

    /*
     * Function getInstance is used to create new game
     * or access to game
     */
    static Game* getInstance(){
        if (theInstance == nullptr){
            theInstance = new Game;
        }
        return theInstance;
    }

    /*
     * Function setDungeonType is used to create dungeon type
     * depending on players
     * @param type is symbol of dungeon type
     */
    void setDungeonType(std::string type);

    /*
     * Function createExampleLevel will build the given example dungeon
     * the map will not be change but item and creature will appear randomly
     * with 60% chance for both
     */
    void createExampleLevel();

    /*
     * Function randomDoorwayType uses to select doorway type randomly
     * with 30% is locked door, 30% is impassable door and 40% is
     * traversable door
     */
    int randomDoorwayType();

    /*
     *
     * Random level can be divided into 2 cases:
     * - One is dungeon with 1 height, 1 row or both
     * - And the rest with heigt > 1 and row > 1
     * @param name, width, height and type are necessary information
     * to create new dungeonLevel
     */
    void createRandomLevel(std::string name, int width, int height, std::string type);

    /*
     * Function displayLevel uses to show the dungeon map
     * on screen
     */
    void displayLevel(std::ostream &display);

    double randomDouble();

    Game(Game const&) = delete;

    void operator = (Game const&) = delete;

    /*
     * Function getDungeon uses to access created dungeon
     * after building
     */
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
