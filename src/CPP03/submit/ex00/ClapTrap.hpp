#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class ClapTrap
{
    // variables
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
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
        const std::string& getName(void) const;
        unsigned int getHitPoints(void) const;
        unsigned int getEnergyPoints(void) const;
        unsigned int getAttackDamage(void) const;
        void setName(const std::string name);
        void setHitPoints(unsigned int hitPoints);
        void setEnergyPoints(unsigned int energyPoints);
        void setAttackDamage(unsigned int attackDamage);
        // operators
        ClapTrap& operator=(const ClapTrap& clapTrap); // copy assignment operator
    private:
};

#endif
