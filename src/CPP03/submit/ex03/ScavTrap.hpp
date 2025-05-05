#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    // functions
    public:
        // special member functions
        ScavTrap(void); // default constructor
        ScavTrap(const ScavTrap& scavTrap); // copy constructor
        ScavTrap(const std::string& name);
        ~ScavTrap(void); // destructor
        // others
        void attack(const std::string& target);
        void guardGate(void);
        virtual unsigned int getInitialHitPoints(void) const;
        unsigned int getInitialEnergyPpoints(void) const;
        unsigned int getInitialAttackDamage(void) const;
        // operators
        ScavTrap& operator=(const ScavTrap& scavTrap); // copy assignment operator
    private:
};

#endif
