#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class ClapTrap
{
    // variables
    public:
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    private:
    // functions
    public:
        // special member functions
        ClapTrap(void); // default constructor
        ClapTrap(const ClapTrap& clapTrap); // copy constructor
        ClapTrap(std::string name);
        ~ClapTrap(void); // destructor
        // others
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // operators
        ClapTrap& operator=(const ClapTrap& clapTrap); // copy assignment operator
    private:
};

#endif
