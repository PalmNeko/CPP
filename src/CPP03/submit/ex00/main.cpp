#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <limits>
#include <iostream>
#include <sstream>
#include <iomanip>

void autoTestMode(const std::string& className, const std::string &name);
void selfTestMode(const std::string& className, const std::string &name);
void printUsage(void);
void printHelpCommand(void);
void printClapTrapStatus(const ClapTrap* trap);
void runLine(const std::string& line, ClapTrap& trap);
ClapTrap *genClapTrap(const std::string& className, const std::string &name);

int main(int argc, char *argv[])
{
    std::string name;

    if (argc < 3)
    {
        printUsage();
        return (1);
    }
    if (argc == 4)
        name = argv[3];
    if (std::string(argv[1]) == "auto")
        autoTestMode(std::string(argv[2]), name);
    else if (std::string(argv[1]) == "self")
        selfTestMode(std::string(argv[2]), name);
    std::cout << "exit" << std::endl;
    return 0;
}

void autoTestMode(const std::string& className, const std::string &name)
{
    ClapTrap *forestP;

    forestP = genClapTrap(className, name);
    if (forestP == NULL)
        return ;
    ClapTrap &frost = *forestP;

    std::cout << "===== unique method =====" << std::endl;
    frost.callSubMethod("whoAmI");
    frost.callSubMethod("highFivesGuys");
    frost.callSubMethod("guardGate");
    std::cout << "==========  unique method" << std::endl;
    printClapTrapStatus(&frost);
    frost.attack("Enemy");
    frost.takeDamage(9);
    frost.beRepaired(9);
    printClapTrapStatus(&frost);
    while (frost.getEnergyPoints() > 0)
        frost.attack("Enemy");
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

void selfTestMode(const std::string& className, const std::string &name)
{
    ClapTrap *trapP;

    trapP = genClapTrap(className, name);
    if (trapP == NULL)
        return ;
    while (1)
    {
        std::string line;
        printClapTrapStatus(trapP);
        std::cout << " > ";
        if (!std::getline(std::cin, line))
            break ;
        runLine(line, *trapP);
    }
    delete trapP;
}

void runLine(const std::string& line, ClapTrap& trap)
{
    unsigned int amount;
    std::string target;
    std::string command;
    std::istringstream iss(line);
    iss >> command;
    if (command == "attack")
    {
        iss >> target;
        trap.attack(target);
    }
    else if (command == "repair")
    {
        iss >> amount;
        trap.beRepaired(amount);
    }
    else if (command == "damage")
    {
        iss >> amount;
        trap.takeDamage(amount);
    }
    else if (command == "help")
        printHelpCommand();
    else if (command == "guard")
        trap.callSubMethod("guardGate");
    else if (command == "who")
        trap.callSubMethod("whoAmI");
    else if (command == "guys")
        trap.callSubMethod("highFiveGuys");
}

ClapTrap *genClapTrap(const std::string& className, const std::string &name)
{
    if (className == "ClapTrap")
        return new(std::nothrow) ClapTrap(name);
    else if (className == "ScavTrap")
        return new(std::nothrow) ScavTrap(name);
    else if (className == "FragTrap")
        return new(std::nothrow) FragTrap(name);
    else if (className == "DiamondTrap")
        return new(std::nothrow) DiamondTrap(name);
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

void printUsage(void)
{
    std::cout << "Usage: prog mode className [name]" << std::endl;
    std::cout << "   mode       auto / self" << std::endl;
    std::cout << "   className  ClapTrap etc..." << std::endl;
    std::cout << "   name       your choice name. opt." << std::endl;
}

void printHelpCommand(void)
{
    std::cout << "ClapTrap commands: " << std::endl;
    std::cout << "   attack target  attack and print message" << std::endl;
    std::cout << "   repair amouont repair yourself and gain amount HP" << std::endl;
    std::cout << "   damage amouont take yourself damage and lose amount HP" << std::endl;
    std::cout << "   guard          print guardGate message. only ScavTrap and DiamondTrap" << std::endl;
    std::cout << "   guys           print highFivesGuys message. only FragTrap and DiamondTrap" << std::endl;
    std::cout << "   who            print whoAmI message. only DiamondTrap" << std::endl;
    std::cout << "   help           print this message." << std::endl;
}
