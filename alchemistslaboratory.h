#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H
#include <room.h>
#include <string>

namespace core::dungeon::magical
{

class AlchemistsLaboratory : public Room
{
public:
    AlchemistsLaboratory(int id);
    ~AlchemistsLaboratory();

    std::string description() override;
};

}

#endif // ALCHEMISTSLABORATORY_H
