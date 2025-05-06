#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
    // functions
    public:
        // special member functions
        Dog(void); // default constructor
        Dog(const Dog& dog); // copy constructor
        ~Dog(void); // destructor
        // others
        void makeSound(void) const;
        Dog& operator=(const Dog& cat);
        // operators
    private:
};

#endif
