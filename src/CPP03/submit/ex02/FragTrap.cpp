#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

/*
 * special member functions
 */
FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
    : ClapTrap(fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
}

/*
 * others: public
 */
void FragTrap::attack(const std::string& target)
{
    const int useEnergy = 1;

    if (this->energyPoints < useEnergy || this->hitPoints <= 0)
        return ;
    this->energyPoints -= useEnergy;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Put your hands up! ...Yay! It's high five!" << std::endl;
}

/*
 * operators
 */
FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    if (this != &fragTrap)
    {
        ClapTrap::operator=(fragTrap);
    }
    return *this;
}

/*
 * others: private
 */
