#include "Character.hpp"

Character::Character(void)
{
    
}

Character::Character(const Character& character)
{
    *this = character;
}

Character::~Character(void)
{
    
}

Character& Character::operator=(const Character& character)
{
    if (this != &character)
    {
    }
    return *this;
}

Character::Character(const std::string& name)
    : name(name)
{}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (this->slot[i] == NULL)
        {
            this->slot[i] = m;
            return ;
        }
    }
    return ;
}

void Character::unequip(int idx)
{
    if (!(0 <= idx && idx < SLOT_SIZE))
        return ;
    this->slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (!(0 <= idx && idx < SLOT_SIZE))
        return ;
    this->slot[idx]->use(target);
}
