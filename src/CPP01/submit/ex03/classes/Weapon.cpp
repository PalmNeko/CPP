#include "Weapon.hpp"
#include <string>

Weapon::Weapon(void)
{}

Weapon::Weapon(std::string type)
    : type(type)
{}

Weapon::Weapon(const Weapon& weapon)
    : type(weapon.type)
{}

Weapon& Weapon::operator=(const Weapon& weapon)
{
    if (this != &weapon)
    {
        this->type = weapon.type;
    }
    return *this;
}

const std::string& Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(const std::string& type)
{
    this->type = type;
}
