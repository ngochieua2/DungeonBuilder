#ifndef MAGICWALL_H
#define MAGICWALL_H
#include <wall.h>

namespace core::dungeon::magical
{

class MagicWall : public Wall
{
public:

    MagicWall();

    ~MagicWall();

    std::string description() override;
};

}

#endif // MAGICWALL_H
