#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

/*
 * special member functions
 */
DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
    : ClapTrap(diamondTrap),
    FragTrap(diamondTrap),
    ScavTrap(diamondTrap),
    name(diamondTrap.name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
    FragTrap(name + "_clap_name"),
    ScavTrap(name + "_clap_name"),
    name(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

/*
 * others: public
 */
void DiamondTrap::attack(const std::string& target)
{
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamondTrap name:" << this->name << ", ClapTrap: " << this->FragTrap::ClapTrap::name << std::endl;
}

/*
 * operators
 */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (this != &diamondTrap)
    {
        ClapTrap::operator=(diamondTrap);
        this->name = diamondTrap.name;
    }
    return *this;
}

/*
 * others: private
 */
