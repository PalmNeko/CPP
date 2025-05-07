#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
        AMateria    *floor;
    public:
        AMateria(void); 
        AMateria(const AMateria& aMateria);
        ~AMateria(void); 
        AMateria& operator=(const AMateria& aMateria);

        AMateria(std::string const & type);

        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
