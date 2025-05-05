#include "ClapTrap.hpp"

#include <iostream>
#include <limits>
#include <sstream>

ClapTrap::ClapTrap(void)
{
    this->setInitialAttributes(this);
    std::cout << " + ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    *this = clapTrap;
    std::cout << " @ Copy(ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name)
{
    this->setInitialAttributes(this);
    std::cout << " + ClapTrap(" << name << ")" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << " - ClapTrap(" << this->getName() << ")" << std::endl;
}

bool ClapTrap::doAttack(void)
{
    const int useEnergy = 1;

    if (this->energyPoints < useEnergy || this->hitPoints <= 0)
        return (false);
    this->energyPoints -= useEnergy;
    return (true);
}

std::string ClapTrap::makeAttackText(const std::string& className, const std::string& target) const
{
    std::ostringstream oss;

    oss << className + " ";
    oss << this->getName() + " attacks " + target;
    oss << ", causing " << this->getAttackDamage() << " points of damage!";
    return oss.str();
}

void ClapTrap::attack(const std::string& target)
{
    if (this->doAttack() == false)
        return ;
    std::cout << this->makeAttackText("ClapTrap", target) << std::endl;
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
