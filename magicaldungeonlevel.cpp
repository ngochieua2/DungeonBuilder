#include "magicaldungeonlevel.h"

using core::dungeon::magical::MagicalDungeonLevel;

MagicalDungeonLevel::MagicalDungeonLevel(std::string &name, int &width, int &height)
{
    _name = name;
    _width = width;
    _height = height;
}

MagicalDungeonLevel::~MagicalDungeonLevel(){};

std::string MagicalDungeonLevel::description(){
    return _name +
            "\nSize: " + std::to_string(_width) + " x " + std::to_string(_height) +
            "\nType: Magical Dungeon\n\n";
}
