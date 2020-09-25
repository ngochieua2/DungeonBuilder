#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include <dungeonlevel.h>
#include <string>

namespace core::dungeon::magical
{

class MagicalDungeonLevel : public DungeonLevel
{
public:
    MagicalDungeonLevel(std::string &name, int &width, int &height);
    ~MagicalDungeonLevel();

    std::string description() override;

};

}

#endif // MAGICALDUNGEONLEVEL_H
