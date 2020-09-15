#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include<wall.h>
#include<doorway.h>
#include<dungeonlevel.h>

class BasicDungeonLevel: public DungeonLevel
{
public:
    BasicDungeonLevel();
    ~BasicDungeonLevel();

    //description() = override

//    void setWall(Wall *wall){
//        _wall = wall;
//    };
//    void setDoorway(Doorway *door){
//        _doorway = door;
//    };
private:
    //Wall *_wall;
    //Doorway *_doorway;
};

#endif // BASICDUNGEONLEVEL_H
