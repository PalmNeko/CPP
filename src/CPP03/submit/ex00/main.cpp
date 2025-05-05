#include "ClapTrap.hpp"
#include <limits>
#include <iostream>
#include <sstream>
#include <iomanip>

void autoTestMode(void);
void selfTestMode(void);
void printClapTrapStatus(const ClapTrap* trap);
ClapTrap *selectClapTrap(void);

int main(void)
{
    std::cout << "0) auto test mode: Select class and auto test it.\n";
    std::cout << "1) self test mode: Select class and self test it by your select value.\n";
    std::cout << "please select mode > ";
    int mode;
    std::cin >> mode;
    if (mode == 0)
        autoTestMode();
    else if (mode == 1)
        selfTestMode();
    std::cout << "exit" << std::endl;
    return 0;
}

void autoTestMode(void)
{
    ClapTrap *forestP;

    forestP = selectClapTrap();
    if (forestP == NULL)
        return ;
    ClapTrap &frost = *forestP;

    printClapTrapStatus(&frost);
    frost.attack("Enemy");
    frost.takeDamage(9);
    frost.beRepaired(9);
    printClapTrapStatus(&frost);
    while (frost.getEnergyPoints() > 0)
    {
        frost.attack("Enemy");
    }
    printClapTrapStatus(&frost);
    frost.beRepaired(2);
    frost.attack("Enemy");
    printClapTrapStatus(&frost);
    frost.takeDamage(1000000000);
    frost.takeDamage(3);
    frost.beRepaired(2);
    frost.attack("Enemy");
    printClapTrapStatus(&frost);
    delete forestP;
}

void selfTestMode(void)
{
    ClapTrap *trapP;

    trapP = selectClapTrap();
    if (trapP == NULL)
        return ;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (1)
    {
        std::string line;
        printClapTrapStatus(trapP);
        std::cout << "(attack | repair | damage) (string | unsigned int) > ";
        if (!std::getline(std::cin, line))
            break ;
        unsigned int amount;
        std::string target;
        std::string command;
        std::istringstream iss(line);
        iss >> command;
        if (command == "attack")
        {
            iss >> target;
            trapP->attack(target);
        }
        else if (command == "repair")
        {
            iss >> amount;
            trapP->beRepaired(amount);
        }
        else if (command == "damage")
        {
            iss >> amount;
            trapP->takeDamage(amount);
        }
    }
    delete trapP;
}

ClapTrap *selectClapTrap(void)
{
    std::string name;

    std::cout << "please input your Name > ";
    std::cin >> name;

    std::cout << "0) ClapTrap\n";
    std::cout << "please select class > ";
    int classNo;
    std::cin >> classNo;
    if (classNo == 0)
        return new(std::nothrow) ClapTrap(name);
    return (NULL);
}

void printClapTrapStatus(const ClapTrap* trap)
{
    std::ostringstream ossForParameter;
    const int lineLength = 38;

    ossForParameter << " HP: " << trap->getHitPoints() << " ATK: " << trap->getAttackDamage() << " ENG: " << trap->getEnergyPoints();
    std::cout << "+----" << std::setw(30) << std::setiosflags(std::ios::left) << std::setfill('-') << trap->getName() << "----+\n";
    std::cout << "|" << std::setw(lineLength) << std::setfill(' ') << ossForParameter.str() << "|" << std::endl;
    std::cout << "+" << std::setw(lineLength) << std::setfill('-') << "" << "+\n";
}
