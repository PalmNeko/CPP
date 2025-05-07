#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *slot[4];
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& materiaSource);
        ~MateriaSource(void);
        MateriaSource& operator=(const MateriaSource& materiaSource);

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif
