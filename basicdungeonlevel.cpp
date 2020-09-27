#include "basicdungeonlevel.h"

using core::dungeon::basic::BasicDungeonLevel;

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height)
{
    _name = name;
    _width = width;
    _height = height;
}

BasicDungeonLevel::~BasicDungeonLevel()
{
}

std::string BasicDungeonLevel::description(){
    return _name +
            "\nSize: " + std::to_string(_width) + " x " + std::to_string(_height) +
            "\nType: Basic Dungeon\n\n";
}
