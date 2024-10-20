#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        FragTrap(void); // default constructor
        FragTrap(const FragTrap& fragTrap); // copy constructor
        FragTrap(const std::string& name);
        ~FragTrap(void); // destructor
        // others
        void attack(const std::string& target);
        void highFivesGuys(void);
        // operators
        FragTrap& operator=(const FragTrap& fragTrap); // copy assignment operator
    private:
};

#endif
