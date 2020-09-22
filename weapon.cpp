#include "weapon.h"


Weapon::Weapon(std::string name)
{
    _name = name;
}

Weapon::~Weapon()
{}

Weapon *Weapon::clone()
{
    return new Weapon(*this);
}
