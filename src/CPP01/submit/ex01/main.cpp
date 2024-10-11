#include "Zombie.hpp"
#include <iostream>
#include <string>

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int main(void)
{
    std::cout << "woke up Tanaka!!" << std::endl;
    Zombie *z_tanaka = newZombie("Tanaka");
    z_tanaka->announce();
    std::cout << "woke up Yamada!!" << std::endl;
    randomChump("Yamada");
    std::cout << "Bang!! > Tanaka!!" << std::endl;
    delete z_tanaka;
    return (0);
}
