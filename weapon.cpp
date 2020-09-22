#include "weapon.h"

using core::items::Weapon;

Weapon::Weapon()
{}

Weapon::~Weapon()
{}

Weapon *Weapon::clone()
{
    return new Weapon(*this);
}
