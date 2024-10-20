#include "FragTrap.hpp"
#include <limits>
#include <iostream>

void testFragTrap(unsigned int hitPoints, unsigned int energyPoints);

int main(void)
{
    testFragTrap(100, 100);
    return 0;
}

void testFragTrap(unsigned int hitPoints, unsigned int energyPoints)
{
    FragTrap frost("Frost");

    frost.attack("Hinge"); // check attack
    frost.takeDamage(hitPoints - 1); // check take damage
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
        frost = FragTrap("Return of Frost");
        std::cout << "frost is revived." << std::endl;
        frost.takeDamage(hitPoints - 1);
        for (unsigned int i = 1; i < energyPoints; i++)
            frost.beRepaired(1);
        frost.attack("ENERGY");
        std::cout << "energy is empty." << std::endl;
        frost.attack("ENERGY");
        frost.beRepaired(1);
        frost.takeDamage(50);
        frost.attack("ENERGY");
        frost.beRepaired(10);
    }
    frost.highFivesGuys();
}
