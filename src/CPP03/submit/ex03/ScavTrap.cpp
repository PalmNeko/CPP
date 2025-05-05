#include "ScavTrap.hpp"

#include <iostream>

/*
 * special member functions
 */
ScavTrap::ScavTrap(void)
{
    this->setInitialAttributes(this);
    std::clog << " + ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
    *this = scavTrap;
    std::clog << " @ Copy(ScavTrap)" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    std::clog << " + ScavTrap(" << name << ")" << std::endl;
    this->setInitialAttributes(this);
}

ScavTrap::~ScavTrap(void)
{
    std::clog << " - ScavTrap(" << this->getName() << ")" << std::endl;
}

/*
 * others: public
 */
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
    const int useEnergy = 1;

    if (this->getEnergyPoints() < useEnergy || this->getHitPoints() <= 0)
        return ;
    this->setEnergyPoints(this->getEnergyPoints() - useEnergy);
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap changed to Gate keeper mode." << std::endl;
}

/*
 * operators
 */
ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        ClapTrap::operator=(scavTrap);
    }
    return *this;
}

/*
 * others: private
 */
