#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
    this->setInitialAttributes(this);
    std::cout << " + ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
    *this = scavTrap;
    std::cout << " @ Copy(ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    this->setInitialAttributes(this);
    std::cout << " + ScavTrap(" << name << ")" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << " - ScavTrap(" << this->getName() << ")" << std::endl;
}

unsigned int ScavTrap::getInitialHitPoints(void) const
{
    return (100);
}
unsigned int ScavTrap::getInitialEnergyPpoints(void) const
{
    return (50);
}
unsigned int ScavTrap::getInitialAttackDamage(void) const
{
    return (20);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->doAttack() == false)
        return ;
    std::cout << this->makeAttackText("ScavTrap", target) << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap changed to Gate keeper mode." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        ClapTrap::operator=(scavTrap);
    }
    return *this;
}
