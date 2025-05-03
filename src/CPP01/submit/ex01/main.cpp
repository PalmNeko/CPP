#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <limits>

Zombie* zombieHorde(int N, std::string name);
static void testZombie(int N, std::string name);

int main(void)
{
    testZombie(3, "Tanaka");
    testZombie(std::numeric_limits<int>::max(), "Ueda");
    testZombie(-1, "Vanilla");
    testZombie(1, "Watanabe");
    testZombie(0, "Xiaomi");
    return (0);
}

static void testZombie(int N, std::string name)
{
    Zombie *zombies;

    try
    {
        zombies = zombieHorde(N, name);
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << name << ": " << "can't allocate." << std::endl;
        return ;
    }
    for (int i = 0; i < N; i++)
        zombies[i].announce();
    delete[] zombies;
}
