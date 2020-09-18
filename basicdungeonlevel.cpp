#include "basicdungeonlevel.h"

BasicDungeonLevel::BasicDungeonLevel(std::string name, int width, int height){
    _name = name;
    _width = width;
    _height = height;
}

BasicDungeonLevel::~BasicDungeonLevel(){}

std::string BasicDungeonLevel::description(){
    return name() + "\nSize: " + std::to_string(width()) + " x " +
            std::to_string(height()) + "Type: Basic Dungeon";
}
