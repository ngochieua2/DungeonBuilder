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

    Monster *clone() override;
};

}

#endif // MONSTER_H
