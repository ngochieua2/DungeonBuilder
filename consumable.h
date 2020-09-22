#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include <item.h>
#include <string>

class Consumable : public Item
{
public:
    Consumable();
    ~Consumable();

    Consumable* clone() override;
};

#endif // CONSUMABLE_H
