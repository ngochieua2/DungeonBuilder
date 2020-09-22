#include "weapon.h"


Weapon::Weapon()
{}

Weapon::~Weapon()
{}

Weapon *Weapon::clone()
{
    return new Weapon(*this);
}
