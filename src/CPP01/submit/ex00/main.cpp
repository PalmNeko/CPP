#include "Zombie.hpp"
#include <iostream>
#include <string>

void randomChump(const std::string& name);
Zombie* newZombie(const std::string& name);

int main(void)
{
    std::cout << "woke up Tanaka!!" << std::endl;
    Zombie *z_tanaka = newZombie("Tanaka");
    z_tanaka->announce();
    delete z_tanaka;
    std::cout << "woke up Yamada!!" << std::endl;
    randomChump("Yamada");
    std::cout << "Bang!! > Tanaka!!" << std::endl;
    return (0);
}
