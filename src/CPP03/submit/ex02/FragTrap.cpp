#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

/*
 * special member functions
 */
FragTrap::FragTrap(void)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
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
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
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

    if (this->getEnergyPoints() < useEnergy || this->getHitPoints() <= 0)
        return ;
    this->setEnergyPoints(this->getEnergyPoints() - useEnergy);
    std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
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
