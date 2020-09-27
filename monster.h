#ifndef MONSTER_H
#define MONSTER_H
#include <abstractcreature.h>
#include <string>

namespace core::creatures
{

class Monster : public AbstractCreature
{
public:

    Monster();

    ~Monster();

    /*!
     * Function clone uses to copy object of Monster
     */
    Monster *clone() override;
};

}

#endif // MONSTER_H
