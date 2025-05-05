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
    (void)hitPoints;
    (void)energyPoints;
    DiamondTrap frost("Frost");
}
