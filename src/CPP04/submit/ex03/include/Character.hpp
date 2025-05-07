#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define SLOT_SIZE 4

class Character : public ICharacter
{
    private:
        AMateria *slot[SLOT_SIZE];
    protected:
        std::string name;
    public:
        Character(void);
        Character(const Character& character);
        ~Character(void);
        Character& operator=(const Character& character);

        Character(const std::string& name);

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
