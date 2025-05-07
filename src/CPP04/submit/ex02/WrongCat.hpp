#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(const WrongCat& WrongCat);
        ~WrongCat(void);
        void makeSound(void) const;
        WrongCat& operator=(const WrongCat& WrongCat);
    private:
};

#endif
