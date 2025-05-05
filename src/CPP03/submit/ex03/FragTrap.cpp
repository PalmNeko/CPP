#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(void)
{
    this->setInitialAttributes(this);
    std::cout << " + FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
    *this = fragTrap;
    std::cout << " @ Copy(FragTrap)" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
{
    this->setInitialAttributes(this);
    std::cout << " + FragTrap(" << name << ")" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << " - FragTrap(" << this->getName() << ")" << std::endl;
}

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
    if (this->doAttack() == false)
        return ;
    std::cout << this->makeAttackText("FragTrap", target) << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Put your hands up! ...Yay! It's high five!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    if (this != &fragTrap)
    {
        ClapTrap::operator=(fragTrap);
    }
    return *this;
}
