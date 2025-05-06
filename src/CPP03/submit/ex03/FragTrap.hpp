#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(const FragTrap& fragTrap);
        FragTrap(const std::string& name);
        ~FragTrap(void);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void highFivesGuys(void);

        unsigned int getInitialHitPoints(void) const;
        unsigned int getInitialEnergyPpoints(void) const;
        unsigned int getInitialAttackDamage(void) const;

        FragTrap& operator=(const FragTrap& fragTrap);
};

#endif
