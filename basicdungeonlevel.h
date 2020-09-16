#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include<dungeonlevel.h>

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel();
    ~BasicDungeonLevel();

    std::string description();


};

#endif // BASICDUNGEONLEVEL_H
