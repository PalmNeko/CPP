#include "Zombie.hpp"
#include <string>

void randomChump(std::string name)
{
    Zombie zombie(name);

    zombie.announce();
    return ;
}
