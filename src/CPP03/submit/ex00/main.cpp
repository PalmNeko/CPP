#include "ClapTrap.hpp"
#include <limits>
#include <iostream>

int main(void)
{
    ClapTrap frost("Frost");

    frost.attack("Hinge");
    frost.takeDamage(9);
    std::cout << "check repaired" << std::endl;
    {
        frost.beRepaired(1);
        frost.takeDamage(1);
        frost.attack("Healer");
    }
    std::cout << "check death" << std::endl;
    {
        frost.takeDamage(std::numeric_limits<unsigned int>::max());
        frost.attack("DEATH"); // not print
        frost.beRepaired(1);
        frost.attack("DEATH"); // not print
    }
    // check energy
    std::cout << "check energy" << std::endl;
    {
        frost = ClapTrap("Return of Frost");
        frost.takeDamage(9);
        for (int i = 0; i < 9; i++)
            frost.beRepaired(1);
        frost.attack("ENERGY");
        frost.attack("ENERGY"); // not print
        frost.beRepaired(10);
        frost.takeDamage(10); // Return of Frost is over.
        frost.attack("ENERGY"); // notprint
        frost.beRepaired(10);
    }
    return 0;
}
