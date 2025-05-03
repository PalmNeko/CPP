#include "Zombie.hpp"
#include <string>

void randomChump(const std::string& name)
{
    Zombie zombie(name);

    zombie.announce();
    return ;
}
