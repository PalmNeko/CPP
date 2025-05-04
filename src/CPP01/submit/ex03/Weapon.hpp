#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(void);
        Weapon(const Weapon& weapon);
        Weapon(std::string type);
        Weapon& operator=(const Weapon& weapon);
        const std::string& getType(void) const;
        void setType(const std::string& type);
};

#endif
