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

    oss << this->makeHeader("  attack  ", className);
    if (this->isAlive() == false)
    {
        oss << "'s HP is zero. can't attack." << std::endl;
        std::cout << "\e[31mFail:\e[0m" << oss.str();
        return ;
    }
    else if (this->useEnergy() == false)
    {
        oss << " there is not enough energy." << std::endl;
        std::cout << "\e[31mFail:\e[0m" << oss.str();
        return ;
    }

    oss << " attacks " + target;
    oss << ", causing \e[34m" << this->getAttackDamage() << "\e[0m points of damage!" << std::endl;
    std::cout << oss.str();
    return ;
}

void ClapTrap::takeDamage(const std::string& className, unsigned int amount)
{
    std::ostringstream oss;

    oss << this->makeHeader("takeDamage", className);
    if (this->isAlive() == false)
    {
        oss << " Stop! life is already zero!" << std::endl;
        std::cout << "\e[31mFail:\e[0m" << oss.str();
        return ;
    }
    if (this->getHitPoints() < amount)
        this->setHitPoints(0);
    else
        this->setHitPoints(this->getHitPoints() - amount);
    oss << " takes \e[31m" << amount << "\e[0m points of damage!";
    oss << " HP: " << this->getHitPoints();
    oss << std::endl;
    std::cout << oss.str();
    return ;
}

void ClapTrap::beRepaired(const std::string& className, unsigned int amount)
{
    std::ostringstream oss;

    oss << this->makeHeader("beRepaired", className);
    if (this->isAlive() == false)
    {
        oss << "'s HP is zero. can't be repaired." << std::endl;
        std::cout << "\e[31mFail:\e[0m" << oss.str();
        return ;
    }
    else if (this->useEnergy() == false)
    {
        oss << " there is not enough energy." << std::endl;
        std::cout << "\e[31mFail:\e[0m" << oss.str();
        return ;
    }
    const unsigned int uintMax = std::numeric_limits<unsigned int>::max();
    if (this->getHitPoints() >= uintMax - amount)
        this->setHitPoints(uintMax);
    else
        this->setHitPoints(this->getHitPoints() + amount);
    oss << " gain \e[32m" << amount << "\e[0m points of health."
        << " HP: " << this->getHitPoints() << std::endl;
    std::cout << oss.str();
    return ;
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

std::string ClapTrap::makeHeader(const std::string& action, const std::string& className) const
{
    std::ostringstream oss;

    oss << " = " << action << " = " << "[ " + className;
    if (this->getName() != "")
        oss << " " + this->getName();
    oss << " ]";
    return oss.str();
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

void ClapTrap::callSubMethod(const std::string&, bool* hasMethod)
{
    if (hasMethod)
        *hasMethod = false;
    return ;
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
