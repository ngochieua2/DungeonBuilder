#ifndef GAME_H
#define GAME_H


class Game
{
public:
    static Game* getInstance(){
        if (theInstance == nullptr){
            theInstance = new Game;
        }
        return theInstance;
    }

    //setDungeonType(DungeonLevelBuilder)
    //createExampleLevel()
    //createRandomLevel(std::string name, int width, int height)
    //displayLevel()
    //double randomDouble()

    Game(Game const&) = delete;
    void operator = (Game const&) = delete;
private:
    static Game* theInstance;
    Game();
    ~Game();

};

#endif // GAME_H
