#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
{
    this->setInitialAttributes(this);
    std::cout << " + DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
{
    *this = diamondTrap;
    std::cout << " @ Copy(DiamondTrap)" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), name(name)
{
    this->setInitialAttributes(this);
    std::cout << " + DiamondTrap(" << name << ")" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << " - DiamondTrap(" << this->name << ")" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamondTrap name:" << this->name << ", ClapTrap: " << this->getName() << std::endl;
}


unsigned int DiamondTrap::getInitialHitPoints(void) const
{
    return (this->FragTrap::getInitialHitPoints());
}

unsigned int DiamondTrap::getInitialEnergyPpoints(void) const
{
    return (this->ScavTrap::getInitialEnergyPpoints());
}

unsigned int DiamondTrap::getInitialAttackDamage(void) const
{
    return (this->FragTrap::getInitialAttackDamage());
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (this != &diamondTrap)
    {
        ClapTrap::operator=(diamondTrap);
        this->name = diamondTrap.name;
    }
    return *this;
}
