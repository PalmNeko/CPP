#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        WrongCat(void); // default constructor
        WrongCat(const WrongCat& WrongCat); // copy constructor
        ~WrongCat(void); // destructor
        // others
        void makeSound(void) const;
        // operators
        WrongCat& operator=(const WrongCat& WrongCat); // copy assignment operator
    private:
};

#endif
