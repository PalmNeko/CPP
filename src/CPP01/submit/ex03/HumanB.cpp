#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name)
    : name(name),
    weapon(NULL)
{}

HumanB::HumanB(const std::string& name, Weapon& weapon)
    : name(name),
    weapon(&weapon)
{}

void HumanB::attack(void) const
{
    if (this->weapon == NULL)
    {
        std::cout << this->name << "have no weapon." << std::endl;
        return ;
    }
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}
