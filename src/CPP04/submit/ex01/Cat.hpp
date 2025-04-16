#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        Cat(void); // default constructor
        Cat(const Cat& cat); // copy constructor
        ~Cat(void); // destructor
        // others
        void makeSound(void) const;
        // operators
    private:
};

#endif
