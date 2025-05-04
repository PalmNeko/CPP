#include "ClapTrap.hpp"

#include <iostream>
#include <limits>

/*
 * special member functions
 */
ClapTrap::ClapTrap(void)
    : hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::clog << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
    : name(clapTrap.name),
    hitPoints(clapTrap.hitPoints),
    energyPoints(clapTrap.energyPoints),
    attackDamage(clapTrap.attackDamage)
{
    std::clog << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name),
    hitPoints(10),
    energyPoints(10),
    attackDamage(0)
{
    std::clog << "Constructor called: " << name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::clog << "Destructor called: " << this->name << std::endl;
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

const std::string& ClapTrap::getName(void) const
{
    return (this->name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
    return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return (this->attackDamage);
}

void ClapTrap::setName(const std::string name)
{
    this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->attackDamage = attackDamage;
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
