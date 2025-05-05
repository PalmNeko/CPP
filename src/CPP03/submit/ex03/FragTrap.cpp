#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

/*
 * special member functions
 */
FragTrap::FragTrap(void)
{
    this->setInitialAttributes(this);
    std::clog << " + FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
    *this = fragTrap;
    std::clog << " @ Copy(FragTrap)" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    std::clog << " + FragTrap(" << name << ")" << std::endl;
    this->setInitialAttributes(this);
}

FragTrap::~FragTrap(void)
{
    std::clog << " - FragTrap(" << this->getName() << ")" << std::endl;
}

/*
 * others: public
 */
unsigned int FragTrap::getInitialHitPoints(void) const
{
    return (100);
}

unsigned int FragTrap::getInitialEnergyPpoints(void) const
{
    return (100);
}

unsigned int FragTrap::getInitialAttackDamage(void) const
{
    return (30);
}

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
