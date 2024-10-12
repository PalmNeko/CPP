#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <limits>

Zombie* zombieHorde(int N, std::string name);
void    testZombie(int N, std::string name);

int main(void)
{
    testZombie(3, "Tanaka");
    try
    {
        testZombie(std::numeric_limits<int>::max(), "Ueda");
    }
    catch (int e)
    {
        std::cout << "expected error!!" << std::endl;
    }
    try
    {
        testZombie(-1, "Vanilla");
    }
    catch (int e)
    {
        std::cout << "expected error!!" << std::endl;
    }
    testZombie(1, "Watanabe");
    testZombie(0, "Xiaomi");
    return (0);
}

void    testZombie(int N, std::string name)
{
    Zombie *zombies;

    zombies = zombieHorde(N, name);
    if (zombies == NULL)
    {
        std::cout << "Memory alloc error! nothrow sample!!" << std::endl;
        throw (1);
    }
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete[] zombies;
}
