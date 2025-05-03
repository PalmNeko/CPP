#include "Harl.hpp"

#include <iostream>

/*
 * others: public
 */

void Harl::complain(std::string level)
{
    enum {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        NONE_LOG_LEVEL,
    };
    struct LevelMap {
        std::string level;
        int value;
    };
    LevelMap map[] = {
        {"DEBUG", DEBUG},
        {"INFO", INFO},
        {"WARNING", WARNING},
        {"ERROR", ERROR},
    };
    
    int mapSize = sizeof(map) / sizeof(map[0]);
    int levelValue = NONE_LOG_LEVEL;
    for (int i = 0; i < mapSize; i++)
    {
        if (map[i].level == level)
        {
            levelValue = map[i].value;
            break ;
        }
    }
    switch (levelValue)
    {
        case DEBUG:
            this->debug();
        case INFO:
            this->info();
        case WARNING:
            this->warning();
        case ERROR:
            this->error();
        break ;
        default:
            this->insignificant();
    }
    return ;
}

/*
 * others: private
 */

void Harl::debug(void) const
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my"
        " 7XL-double-cheese-triple-pickle-special ketchup burger. " << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) const
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) const
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error(void) const
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout <<
        "This is unacceptable, "
        "I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::insignificant(void) const
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
