#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(const std::string& name);
        HumanB(const std::string& name, Weapon& weapon);
        void attack(void) const;
        void setWeapon(Weapon& weapon);
};

#endif
