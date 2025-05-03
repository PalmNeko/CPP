#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
    private:
        std::string name;
        Weapon weapon;
    public:
        HumanA(std::string name, const Weapon& weapon);
        void attack(void) const;
};

#endif
