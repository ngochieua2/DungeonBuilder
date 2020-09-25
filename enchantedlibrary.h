#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H
#include <room.h>
#include <string>

namespace  core::dungeon::magical
{

class EnchantedLibrary : public Room
{
public:
    EnchantedLibrary(int id);
    ~EnchantedLibrary();

    std::string description() override;
};

}

#endif // ENCHANTEDLIBRARY_H
