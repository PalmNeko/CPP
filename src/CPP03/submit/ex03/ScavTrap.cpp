#include "ScavTrap.hpp"
#include <iostream>
#include <sstream>

ScavTrap::ScavTrap(void)
{
    this->setInitialAttributes(this);
    std::cout << " + ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
    : ClapTrap(scavTrap)
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
    this->ClapTrap::attack("ScavTrap", target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
    this->ClapTrap::takeDamage("ScavTrap", amount);
}
void ScavTrap::beRepaired(unsigned int amount)
{
    this->ClapTrap::beRepaired("ScavTrap", amount);
}

void ScavTrap::guardGate(void)
{
    std::ostringstream oss;

    oss << this->makeHeader("guardGate", "ScavTrap");
    if (!this->isAlive())
    {
        std::cout << this->failMessage << oss.str() << " can't move." << std::endl;
    }
    std::cout << oss.str() << " change to Gate keeper mode." << std::endl;
}

void ScavTrap::callSubMethod(const std::string& method, bool* hasMethod)
{
    if (hasMethod)
        *hasMethod = false;
    if (method == "guardGate")
    {
        this->guardGate();
        if (hasMethod)
            *hasMethod = true;
    }
    return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        ClapTrap::operator=(scavTrap);
    }
    return *this;
}
