#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H
#include <dungeonlevel.h>
#include <string>

namespace core::dungeon::basic
{

class BasicDungeonLevel : public DungeonLevel
{
public:

    /*!
     * Constructor BasicDungeonLevel use to use basic information to build
     * a BasicDungeonLevel
     * @param name, width, height are name of dungeon, number of columns and
     * number of rows, respectively
     */
    BasicDungeonLevel(std::string name, int width, int height);

    ~BasicDungeonLevel();

    /*!
     * Function description uses to print basic information of current
     * dungeon, including name, size(width, height) and type.
     */
    std::string description() override;

};

}

#endif // BASICDUNGEONLEVEL_H
