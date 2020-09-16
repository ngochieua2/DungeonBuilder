#include "basicdungeonlevel.h"


BasicDungeonLevel::BasicDungeonLevel(){

}
BasicDungeonLevel::~BasicDungeonLevel(){}

std::string BasicDungeonLevel::description(){

    return name() + "\n" + "Size: " + std::to_string(width()) + " x " + std::to_string(height()) + "\n" +
            "Type: Basic Dungeon";
}
