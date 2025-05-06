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

        void attack(const std::string& className, const std::string& target);
        void takeDamage(const std::string& className, unsigned int amount);
        void beRepaired(const std::string& className, unsigned int amount);
        bool useEnergy(void);
        bool isAlive(void) const;
        void setInitialAttributes(const ClapTrap *clapTrap);

    public:
        ClapTrap(void);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap(std::string name);
        virtual ~ClapTrap(void);

        virtual void attack(const std::string& target);
        virtual void takeDamage(unsigned int amount);
        virtual void beRepaired(unsigned int amount);

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

        virtual void callSubMethod(const std::string& method, bool* hasMethod = NULL);

        ClapTrap& operator=(const ClapTrap& clapTrap);
};

#endif
