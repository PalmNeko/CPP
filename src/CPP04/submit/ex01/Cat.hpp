#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain* brain;
    public:
        Cat(void);
        Cat(const Cat& cat);
        ~Cat(void);

        void makeSound(void) const;
        Cat& operator=(const Cat& cat);
        Cat *clone(void) const;
};

#endif
