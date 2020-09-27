#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H
#include <dungeonlevel.h>
#include <string>

namespace core::dungeon::magical
{

class MagicalDungeonLevel : public DungeonLevel
{
public:

    /*!
     * Constructor BasicDungeonLevel use to use basic information to build
     * a MagicalDungeonLevel.
     * @param name, width, height are name of dungeon, number of columns and
     * number of rows, respectively.
     */
    MagicalDungeonLevel(std::string name, int width, int height);

    ~MagicalDungeonLevel();

    /*!
     * Function description uses to print basic information of current
     * dungeon, including name, size(width, height) and type.
     */
    std::string description() override;

};

}

#endif // MAGICALDUNGEONLEVEL_H
