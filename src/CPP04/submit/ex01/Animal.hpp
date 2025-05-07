#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal& animal);
        Animal(const std::string& type);
        virtual ~Animal(void);

        virtual void makeSound(void) const;
        const std::string& getType(void) const;

        Animal& operator=(const Animal& animal);
    private:
};

#endif
