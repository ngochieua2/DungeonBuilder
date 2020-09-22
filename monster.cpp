#include "monster.h"

Monster::Monster(std::string name)
{
    _name = name;
}

Monster::~Monster()
{}

Monster *Monster::clone()
{
    return new Monster(*this);
}
