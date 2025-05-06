#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap: public FragTrap, public ScavTrap
{

    private:
        std::string name;

    public:
        DiamondTrap(void);
        DiamondTrap(const DiamondTrap& diamondTrap);
        DiamondTrap(const std::string& name);
        ~DiamondTrap(void);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void whoAmI(void) const;

        unsigned int getInitialHitPoints(void) const;
        unsigned int getInitialEnergyPpoints(void) const;
        unsigned int getInitialAttackDamage(void) const;

        void callSubMethod(const std::string& method, bool* hasMethod = NULL);

        DiamondTrap& operator=(const DiamondTrap& diamondTrap);
};

#endif
