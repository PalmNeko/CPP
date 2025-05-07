#ifndef I_MATERIA_SOURCE_HPP
# define I_MATERIA_SOURCE_HPP

# include "AMateria.hpp"
# include <string>

class IMateriaSource
{
    public:
        virtual ~IMateriaSource(void);
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
