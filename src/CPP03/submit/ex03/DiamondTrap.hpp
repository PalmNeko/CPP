#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>

class DiamondTrap: public FragTrap, public ScavTrap
{
    // variables
    public:
    private:
        std::string name;
    // functions
    public:
        // special member functions
        DiamondTrap(void); // default constructor
        DiamondTrap(const DiamondTrap& diamondTrap); // copy constructor
        DiamondTrap(const std::string& name);
        ~DiamondTrap(void); // destructor
        // others
        void attack(const std::string& target);
        void whoAmI(void) const;
        // operators
        DiamondTrap& operator=(const DiamondTrap& diamondTrap); // copy assignment operator
    private:
};

#endif
