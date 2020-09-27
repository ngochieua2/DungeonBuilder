#include "monster.h"

using core::creatures::Monster;

Monster::Monster()
{
}

Monster::~Monster()
{
}

Monster *Monster::clone()
{
    return new Monster(*this);
}
