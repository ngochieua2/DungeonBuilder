#ifndef ROCKWALL_H
#define ROCKWALL_H
#include <wall.h>

namespace core::dungeon::basic{

class RockWall : public Wall
{
public:
    RockWall();
    ~RockWall();

    std::string description() override;
};

}

#endif // ROCKWALL_H
