#include "basicdungeonlevel.h"

using core::dungeon::basic::BasicDungeonLevel;

/*
 * Constructor BasicDungeonLevel use to get basic information to build
 * a BasicDungeonLevel
 * @param name, width, height are name of dungeon, number of columns and
 * number of rows, respectively
 */
BasicDungeonLevel::BasicDungeonLevel(std::string &name, int &width, int &height)
{
    _name = name;
    _width = width;
    _height = height;
}

/*
 * there is a destructor of BasicDungeonLevel
 * There is no thing to delete in this class
 */

BasicDungeonLevel::~BasicDungeonLevel()
{
}

/*
 * Function description uses to print basic information of current
 * dungeon, including name, size(width, height) and type.
 */

std::string BasicDungeonLevel::description(){
    return _name +
            "\nSize: " + std::to_string(_width) + " x " + std::to_string(_height) +
            "\nType: Basic Dungeon\n\n";
}
