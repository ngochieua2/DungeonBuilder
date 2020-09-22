#include "monster.h"

Monster::Monster()
{}

Monster::~Monster()
{}

Monster *Monster::clone()
{
    return new Monster(*this);
}
