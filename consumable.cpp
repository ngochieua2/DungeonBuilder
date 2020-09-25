#include "consumable.h"

using core::items::Consumable;

Consumable::Consumable()
{
}

Consumable::~Consumable()
{
}

/*
 * Function clone uses to copy object of Consumable
 */

Consumable *Consumable::clone()
{
    return new Consumable(*this);
}
