#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

template <class Meta, class Real>
    void testAnimal(void);
template <class Animal>
    void printSound(const std::string& header, const Animal& animal);
template <class Meta, class Real>
    void testCopy(Meta* instance);

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    testAnimal<Animal, Animal>();
    testAnimal<Animal, Cat>();
    testAnimal<Animal, Dog>();
    testAnimal<WrongAnimal, WrongAnimal>();
    testAnimal<WrongAnimal, WrongCat>();
    return 0;
}

template <class Animal>
    void printSound(const std::string& header, const Animal& animal)
{
    std::cout << "[ " + header + " ]" << " type: " << animal->getType() << " Sound: ";
    animal->makeSound();
}

template <class Meta, class Real>
    void testAnimal(void)
{
    std::cout << "==== test ====" << std::endl;
    {
        Real instance;
        printSound("instance", &instance);
        testCopy<Meta, Real>(&instance);
    }
    std::cout << "=============" << std::endl;
}

template <class Meta, class Real>
    void testCopy(Meta* instance)
{
    printSound("upCast", instance);
    {
        Meta copy_constructor = Meta(*instance);
        printSound("copy_constructor", &copy_constructor);
    }
    {
        Meta copy_assignment;
        copy_assignment = *instance;
        printSound("copy_assignment", &copy_assignment);
    }
    {
        Meta *downCast_copy_constructor = new Real(*dynamic_cast<Real *>(instance));
        printSound("downCast_copy_constructor", downCast_copy_constructor);
        delete downCast_copy_constructor;
    }
    {
        Real downCast_copy_assignment;
        downCast_copy_assignment = *dynamic_cast<Real *>(instance);
        printSound("downCast_copy_assignment", &downCast_copy_assignment);
    }
}
