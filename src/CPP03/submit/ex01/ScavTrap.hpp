#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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
        // operators
        ScavTrap& operator=(const ScavTrap& scavTrap); // copy assignment operator
    private:
};

#endif
