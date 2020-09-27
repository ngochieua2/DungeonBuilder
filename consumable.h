#ifndef CONSUMABLE_H
#define CONSUMABLE_H
#include <item.h>
#include <string>

namespace core::items
{

class Consumable : public Item
{
public:

    Consumable();

    ~Consumable();

    /*
     * Function clone uses to copy object of Consumable
     */
    Consumable* clone() override;

};

}

#endif // CONSUMABLE_H
