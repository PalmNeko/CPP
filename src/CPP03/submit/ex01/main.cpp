#include "ScavTrap.hpp"
#include <limits>
#include <iostream>

int main(void)
{
    ScavTrap frost("Frost");

    frost.attack("Hinge"); // check attack
    frost.takeDamage(99); // check take damage
    // check repaired
    {
        frost.beRepaired(1);
        frost.takeDamage(1);
        frost.attack("Healer"); // must run
    }
    // check death
    {
        frost.takeDamage(std::numeric_limits<unsigned int>::max());
        std::cout << "frost is dead." << std::endl;
        frost.attack("DEATH");
        frost.beRepaired(1);
        frost.attack("DEATH");
    }
    // check energy
    {
        frost = ScavTrap("Return of Frost");
        std::cout << "frost is revived." << std::endl;
        std::cout << "frost is revived." << std::endl;
        frost.takeDamage(99);
        for (int i = 0; i < 49; i++)
            frost.beRepaired(1);
        frost.attack("ENERGY");
        std::cout << "energy is empty." << std::endl;
        frost.attack("ENERGY");
        frost.beRepaired(1);
        frost.takeDamage(50);
        frost.attack("ENERGY");
        frost.beRepaired(10);
    }
    frost.guardGate();
    return 0;
}
