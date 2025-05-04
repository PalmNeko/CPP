#include "ScavTrap.hpp"

#include <iostream>

/*
 * special member functions
 */
ScavTrap::ScavTrap(void)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::clog << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
    : ClapTrap(scavTrap)
{
    std::clog << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::clog << "ScavTrap string constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::clog << "ScavTrap destructor called." << std::endl;
}

/*
 * others: public
 */
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
