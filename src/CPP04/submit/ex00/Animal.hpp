#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    // variables
    protected:
        std::string type;
    // functions
    public:
        // special member functions
        Animal(void); // default constructor
        Animal(const Animal& animal); // copy constructor
        Animal(const std::string& type); // copy constructor
        virtual ~Animal(void); // destructor
        // others
        virtual void makeSound(void) const;
        const std::string& getType(void) const;
        // operators
        Animal& operator=(const Animal& animal); // copy assignment operator
    private:
};

#endif
