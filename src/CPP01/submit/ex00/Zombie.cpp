#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(void)
    :name("")
{}

Zombie::Zombie(const std::string& name)
    :name(name)
{}

Zombie::~Zombie(void)
{
    std::cout << this->name << ": Freeeze!!" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
