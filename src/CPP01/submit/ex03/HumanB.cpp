#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(const std::string& name)
    : name(name)
{}

void HumanB::attack(void) const
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(const Weapon& weapon)
{
    this->weapon = weapon;
}
