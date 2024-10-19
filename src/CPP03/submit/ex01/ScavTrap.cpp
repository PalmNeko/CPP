#include "ScavTrap.hpp"

#include <iostream>

/*
 * special member functions
 */
ScavTrap::ScavTrap(void)
{
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

    if (this->energyPoints < useEnergy || this->hitPoints <= 0)
        return ;
    this->energyPoints -= useEnergy;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
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
