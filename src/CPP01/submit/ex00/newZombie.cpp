#include "Zombie.hpp"
#include <string>

Zombie* newZombie(const std::string& name)
{
    return (new Zombie(name));
}
