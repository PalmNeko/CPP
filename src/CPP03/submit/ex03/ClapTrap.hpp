#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    
    protected:
        bool doAttack(void);
        std::string makeAttackText(const std::string& className, const std::string& target) const;
        void setInitialAttributes(const ClapTrap *clapTrap);
    
    public:
        ClapTrap(void);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap(std::string name);
        ~ClapTrap(void);
        
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

        virtual unsigned int getInitialHitPoints(void) const;
        virtual unsigned int getInitialEnergyPpoints(void) const;
        virtual unsigned int getInitialAttackDamage(void) const;

        ClapTrap& operator=(const ClapTrap& clapTrap);
};

#endif
