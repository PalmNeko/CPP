#include "ClapTrap.hpp"

#include <iostream>
#include <limits>

/*
 * special member functions
 */
ClapTrap::ClapTrap(void)
{
    this->setInitialAttributes(this);
    std::clog << " + ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    *this = clapTrap;
    std::clog << " @ Copy(ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name)
{
    std::clog << " + ClapTrap(" << name << ")" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::clog << " - ClapTrap(" << this->getName() << ")" << std::endl;
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

void ClapTrap::setInitialAttributes(const ClapTrap *clapTrap)
{
    this->setHitPoints(clapTrap->getInitialHitPoints());
    this->setEnergyPoints(clapTrap->getInitialEnergyPpoints());
    this->setAttackDamage(clapTrap->getInitialAttackDamage());
}

unsigned int ClapTrap::getInitialHitPoints(void) const
{
    return (10);
}

unsigned int ClapTrap::getInitialEnergyPpoints(void) const
{
    return (10);
}

unsigned int ClapTrap::getInitialAttackDamage(void) const
{
    return (0);
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
