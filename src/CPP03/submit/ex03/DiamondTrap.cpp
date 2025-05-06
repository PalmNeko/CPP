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
    : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap)
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

void DiamondTrap::takeDamage(unsigned int amount)
{
    this->ClapTrap::takeDamage("DiamondTrap", amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
    this->ClapTrap::beRepaired("DiamondTrap", amount);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << this->makeHeader("  whoAmI  ", "DiamondTrap") << " I'm " << this->name << ".";
    std::cout << " ClapTrap's name is " << this->getName() << std::endl;
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

void DiamondTrap::callSubMethod(const std::string& method, bool* hasMethod)
{
    if (hasMethod)
        *hasMethod = false;
    if (method == "whoAmI")
    {
        this->whoAmI();
        if (hasMethod)
            *hasMethod = true;
    }
    else
    {
        bool _hasMethod;
        _hasMethod = false;
        this->ScavTrap::callSubMethod(method, &_hasMethod);
        if (hasMethod)
            *hasMethod = _hasMethod;
        if (_hasMethod)
            return ;
        this->FragTrap::callSubMethod(method, &_hasMethod);
        if (hasMethod)
            *hasMethod = _hasMethod;
        if (_hasMethod)
            return ;
    }
    return ;
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
