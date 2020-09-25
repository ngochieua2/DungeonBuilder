#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H
#include <string>

namespace core::creatures
{

class AbstractCreature
{
public:
    AbstractCreature();
    AbstractCreature(std::string name);
    virtual ~AbstractCreature();

    virtual AbstractCreature *clone() = 0;

    void setName(std::string name);

    std::string name();

    char displayCharacter();

    void setBoss(bool value);

    bool isBoss();

protected:
    std::string _name{};
    bool Boss{false};
};

}

#endif // ABSTRACTCREATURE_H
