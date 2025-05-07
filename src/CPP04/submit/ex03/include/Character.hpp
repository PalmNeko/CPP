#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define SLOT_SIZE 4

class Character : public ICharacter
{
    private:
        AMateria *slot[SLOT_SIZE];
        bool hasAlreadyMateria(AMateria* m);
    protected:
        std::string name;
    public:
        Character(void);
        Character(const Character& character);
        ~Character(void);
        Character& operator=(const Character& character);

        Character(const std::string& name);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        AMateria *pickMateria(int idx);
};

#endif
