#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(const ScavTrap& scavTrap);
        ScavTrap(const std::string& name);
        ~ScavTrap(void);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void guardGate(void);

        unsigned int getInitialHitPoints(void) const;
        unsigned int getInitialEnergyPpoints(void) const;
        unsigned int getInitialAttackDamage(void) const;

        virtual void callSubMethod(const std::string& method, bool* hasMethod = NULL);

        ScavTrap& operator=(const ScavTrap& scavTrap);
    private:
};

#endif
