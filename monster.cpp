#include "monster.h"

Monster::Monster(std::string name)
{}

Monster::~Monster()
{}

Monster *Monster::clone()
{
    return new Monster(*this);
}
