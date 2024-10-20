#include "ClapTrap.hpp"

#include <iostream>
#include <limits>

/*
 * special member functions
 */
ClapTrap::ClapTrap(void)
{
    std::clog << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
    : name(clapTrap.name),
    hitPoints(clapTrap.hitPoints),
    energyPoints(clapTrap.energyPoints),
    attackDamage(clapTrap.attackDamage)
{
    std::clog << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::clog << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::clog << "ClapTrap destructor called" << std::endl;
}

/*
 * others: public
 */
void ClapTrap::attack(const std::string& target)
{
    const int useEnergy = 1;

    if (this->energyPoints < useEnergy || this->hitPoints <= 0)
        return ;
    this->energyPoints -= useEnergy;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
        return ;
    if (this->hitPoints < amount)
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    const int useEnergy = 1;
    const unsigned int uintMax = std::numeric_limits<unsigned int>::max();

    if (this->energyPoints < useEnergy || this->hitPoints <= 0)
        return ;
    this->energyPoints -= useEnergy;
    if (this->hitPoints >= uintMax - amount)
        this->hitPoints = uintMax;
    else
        this->hitPoints += amount;
}

/*
 * operators
 */
ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    if (this != &clapTrap)
    {
        this->name = clapTrap.name;
        this->hitPoints = clapTrap.hitPoints;
        this->energyPoints = clapTrap.energyPoints;
        this->attackDamage = clapTrap.attackDamage;
    }
    return *this;
}

/*
 * others: private
 */
