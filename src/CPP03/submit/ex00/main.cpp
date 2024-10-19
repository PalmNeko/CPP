#include "ClapTrap.hpp"
#include <limits>

int main(void)
{
    ClapTrap frost("Frost");

    frost.attack("Hinge"); // check attack
    frost.takeDamage(9); // check take damage
    // check repaired
    {
        frost.beRepaired(1);
        frost.takeDamage(1);
        frost.attack("Healer"); // must run
    }
    // check death
    {
        frost.takeDamage(std::numeric_limits<unsigned int>::max());
        frost.attack("DEATH");
        frost.beRepaired(1);
        frost.attack("DEATH");
    }
    // check energy
    {
        frost = ClapTrap("Return of Frost");
        frost.takeDamage(9);
        for (int i = 0; i < 9; i++)
            frost.beRepaired(1);
        frost.attack("ENERGY"); // energy is empty after attack
        frost.attack("ENERGY");
        frost.beRepaired(10);
        frost.takeDamage(10); // Return of Frost is over.
        frost.attack("ENERGY");
        frost.beRepaired(10);
    }
    return 0;
}
