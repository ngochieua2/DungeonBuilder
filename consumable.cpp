#include "consumable.h"

using core::items::Consumable;

Consumable::Consumable()
{}

Consumable::~Consumable()
{}

Consumable *Consumable::clone()
{
    return new Consumable(*this);
}
