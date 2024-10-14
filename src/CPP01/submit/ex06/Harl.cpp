#include "Harl.hpp"

#include <iostream>

/*
 * special member functions
 */
Harl::Harl(void)
{}

Harl::Harl(const Harl& harl)
{
    (void)harl;
}

Harl::~Harl(void)
{}

/*
 * operators
 */
Harl& Harl::operator=(const Harl& harl)
{
    if (this != &harl)
    {
    }
    return *this;
}

/*
 * others: public
 */

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my"
        " 7XL-double-cheese-triple-pickle-special ketchup burger. " << std::endl;
    std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout <<
        "This is unacceptable, "
        "I want to speak to the manager now." << std::endl;
}

void Harl::insignificant(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
    struct LevelMap {
        std::string level;
        void (Harl::*claim)(void);
    };
    // claim2 = &Harl::debug;
    LevelMap map[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error},
    };
    int mapSize = sizeof(map) / sizeof(map[0]);
    bool harlSwitch = false;
    for (int i = 0; i < mapSize; i++)
    {
        if (map[i].level == level || harlSwitch)
        {
            std::cout << "[ " + map[i].level + " ]" << std::endl;
            (this->*(map[i].claim))();
            std::cout << std::endl;
            harlSwitch = true;
        }
    }
    if (harlSwitch == false)
        this->insignificant();
    return ;
}

/*
 * others: private
 */
