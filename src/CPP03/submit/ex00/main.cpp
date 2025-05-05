#include "ClapTrap.hpp"
#include <limits>
#include <iostream>

int main(void)
{
    ClapTrap frost("Frost");

    frost.attack("Hinge");
    frost.takeDamage(9);
    {
        frost.beRepaired(1);
        frost.takeDamage(1);
        frost.attack("Healer");
    }
    {
        frost.takeDamage(std::numeric_limits<unsigned int>::max());
        frost.attack("DEATH");
        frost.beRepaired(1);
        frost.attack("DEATH");
    }
    {
        frost = ClapTrap("Return of Frost");
        frost.takeDamage(9);
        for (int i = 0; i < 9; i++)
            frost.beRepaired(1);
        frost.attack("ENERGY");
        frost.attack("ENERGY");
        frost.beRepaired(10);
        frost.takeDamage(10);
        frost.attack("ENERGY");
        frost.beRepaired(10);
    }
    return 0;
}
