#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include<dungeonlevel.h>
#include<string>

class BasicDungeonLevel : public DungeonLevel
{
public:
    BasicDungeonLevel(std::string name, int width, int height);
    ~BasicDungeonLevel();

    std::string description() override;

};

#endif // BASICDUNGEONLEVEL_H
