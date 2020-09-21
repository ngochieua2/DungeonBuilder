#include "weapon.h"


Weapon::Weapon(std::string name)
{}

Weapon::~Weapon()
{}

Weapon *Weapon::clone()
{
    return new Weapon(*this);
}
