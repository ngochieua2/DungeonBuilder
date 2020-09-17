#include "basicdungeonlevel.h"

BasicDungeonLevel::BasicDungeonLevel(){}

BasicDungeonLevel::~BasicDungeonLevel(){}

std::string BasicDungeonLevel::description(){
    return name() + "\nSize: " + std::to_string(width()) + " x " +
            std::to_string(height()) + "Type: Basic Dungeon";
}
