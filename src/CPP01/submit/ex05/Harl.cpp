
#include "Harl.hpp"
#include <iostream>

void Harl::complain(std::string level) const
{
	struct LevelMap {
		std::string level;
		void (Harl::*claim)(void) const;
	};
	// claim2 = &Harl::debug;
	LevelMap map[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};
	int mapSize = sizeof(map) / sizeof(map[0]);
	for (int i = 0; i < mapSize; i++)
	{
		if (map[i].level == level)
		{
			(this->*(map[i].claim))();
			break ;
		}
	}
	return ;
}

void Harl::warning(void) const
{
	std::cout <<
		"[WARNING] I think I deserve to have some extra bacon for free."
		" I’ve been coming for years whereas you started working here"
		" since last month." << std::endl;
}

void Harl::info(void) const
{
	std::cout <<
		"[INFO] I cannot believe adding extra bacon costs more money."
		" You didn’t put enough bacon in my burger!"
		" If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::error(void) const
{
	std::cout <<
		"[ERROR] This is unacceptable!"
		" I want to speak to the manager now." << std::endl;
}

void Harl::debug(void) const
{
	std::cout <<
		"[DEBUG] I love having extra bacon for my"
		" 7XL-double-cheese-triple-pickle-special ketchup burger. "
		"I really do!" << std::endl;
}
