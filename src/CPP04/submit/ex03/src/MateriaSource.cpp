#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
    *this = materiaSource;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        delete this->slot[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
    if (this != &materiaSource)
    {
        for (int i = 0; i < 4; i++)
            delete this->slot[i];
        for (int i = 0; i < 4; i++)
        {
            this->slot[i] = materiaSource.slot[i]->clone();
            if (this->slot[i] == NULL)
                return (*this);
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] == materia)
            return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] == materia)
            return ;
        if (this->slot[i] == NULL)
        {
            this->slot[i] = materia;
            return ;
        }
    }
    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] != NULL && this->slot[i]->getType() == type)
        {
            return this->slot[i]->clone();
        }
    }
    return (NULL);
}
