#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
    protected:
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& materiaSource);
        ~MateriaSource(void);
        MateriaSource& operator=(const MateriaSource& materiaSource);

        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
