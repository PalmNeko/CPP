#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <limits>
#include <iostream>

void testDiamondTrap(unsigned int hitPoints, unsigned int energyPoints);

int main(void)
{
    testDiamondTrap(100, 50);
    return 0;
}

void testDiamondTrap(unsigned int hitPoints, unsigned int energyPoints)
{
    DiamondTrap frost("Frost");

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
        frost = DiamondTrap("Return of Frost");
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
    frost.guardGate();
    frost.whoAmI();
}
