#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
    protected:
    public:
        Ice(void);
        Ice(const Ice& ice);
        ~Ice(void);
        Ice& operator=(const Ice& ice);
        void use(ICharacter& target);
        virtual Ice* clone() const;
};

#endif
