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

bool ClapTrap::isAlive(void) const
{
    return (this->getHitPoints() > 0);
}

void ClapTrap::attack(const std::string& className, const std::string& target)
{
    std::ostringstream oss;
    const std::string fullName = className + " " + this->getName();

    oss << fullName;
    if (this->isAlive() == false)
    {
        oss << "'s life is zero. can't attack." << std::endl;
        std::cout << oss.str();
        return ;
    }
    else if (this->useEnergy() == false)
    {
        oss << " can't attack because there is not enough energy." << std::endl;
        std::cout << oss.str();
        return ;
    }

    oss << " attacks " + target;
    oss << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    std::cout << oss.str();
    return ;
}

void ClapTrap::takeDamage(const std::string& className, unsigned int amount)
{
    std::ostringstream oss;
    const std::string fullName = className + " " + this->getName();

    if (this->isAlive() == false)
    {
        oss << "Stop it already!";
        oss << " " << fullName << "'s life is already at zero!" << std::endl;
        std::cout << oss.str();
        return ;
    }
    if (this->getHitPoints() < amount)
        this->setHitPoints(0);
    else
        this->setHitPoints(this->getHitPoints() - amount);
    oss << fullName << " takes " << amount << " points of damage!";
    if (this->isAlive() == false)
        oss << " life is zero.";
    oss << std::endl;
    std::cout << oss.str();
    return ;
}

void ClapTrap::beRepaired(const std::string& className, unsigned int amount)
{
    const unsigned int uintMax = std::numeric_limits<unsigned int>::max();
    const std::string fullName = className + " " + this->getName();

    if (this->isAlive() == false)
    {
        std::cout << fullName << "'s broken. can't be repaired." << std::endl;
        return ;
    }
    else if (this->useEnergy() == false)
    {
        std::cout << fullName << " has no energy for repair." << std::endl;
        return ;
    }
    if (this->getHitPoints() >= uintMax - amount)
        this->setHitPoints(uintMax);
    else
        this->setHitPoints(this->getHitPoints() + amount);
    std::cout << fullName << " be repaired. HP: " << this->getHitPoints() << std::endl;
}

bool ClapTrap::useEnergy(void)
{
    const unsigned int amount = 1;
    if (this->getEnergyPoints() < amount)
        return (false);
    this->setEnergyPoints(this->getEnergyPoints() - amount);
    return (true);
}

void ClapTrap::attack(const std::string& target)
{
    this->attack("ClapTrap", target);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->takeDamage("ClapTrap", amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->beRepaired("ClapTrap", amount);
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
