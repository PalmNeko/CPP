#include "Character.hpp"

Character::Character(void)
{
    for (int i = 0; i < SLOT_SIZE; i++)
        this->slot[i] = NULL;
}

Character::Character(const Character& character)
{
    *this = character;
}

Character::~Character(void)
{
    for (int i = 0; i < SLOT_SIZE; i++)
        delete this->slot[i];
}

Character& Character::operator=(const Character& character)
{
    if (this != &character)
    {
        for (int i = 0; i < SLOT_SIZE; i++)
            delete this->slot[i];
        int i = 0;
        for (i = 0; i < SLOT_SIZE; i++)
        {
            this->slot[i] = character.slot[i]->clone();
            if (this->slot[i] == NULL)
                return *this;
        }
    }
    return *this;
}

Character::Character(const std::string& name)
    : name(name)
{
    for (int i = 0; i < SLOT_SIZE; i++)
        this->slot[i] = NULL;
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (this->hasAlreadyMateria(m))
        return ;
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
    if (this->slot[idx] == NULL)
        return ;
    this->slot[idx]->use(target);
}

AMateria *Character::pickMateria(int idx)
{
    if (0 <= idx && idx < SLOT_SIZE)
        return this->slot[idx];
    return (NULL);
}

bool Character::hasAlreadyMateria(AMateria* m)
{
    for (int i = 0; i < SLOT_SIZE; i++)
    {
        if (this->slot[i] == m)
            return true;
    }
    return false;
}
