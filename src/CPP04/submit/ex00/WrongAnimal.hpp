#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
    // variables
    protected:
        std::string type;
    // functions
    public:
        // special member functions
        WrongAnimal(void); // default constructor
        WrongAnimal(const WrongAnimal& WrongAnimal); // copy constructor
        WrongAnimal(const std::string& type); // copy constructor
        ~WrongAnimal(void); // destructor
        // others
        void makeSound(void) const;
        // operators
        WrongAnimal& operator=(const WrongAnimal& WrongAnimal); // copy assignment operator
    private:
};

#endif
