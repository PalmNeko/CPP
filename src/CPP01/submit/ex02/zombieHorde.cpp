#include "Zombie.hpp"
#include <string>
#include <new>

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombies;

    zombies = new (std::nothrow) Zombie[N];
    if (zombies == NULL)
        return (NULL);
    for (int i = 0; i < N; i++)
        zombies[i].setName(name);
    return (zombies);
}
