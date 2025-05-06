#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& WrongAnimal);
        WrongAnimal(const std::string& type);
        virtual ~WrongAnimal(void);

        void makeSound(void) const;
        const std::string& getType(void) const;

        WrongAnimal& operator=(const WrongAnimal& WrongAnimal);
    private:
};

#endif
