#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void testWrongCat(void);
void testAnimal(void);

int main(void) {
    testAnimal();
    testWrongCat();
}

void testAnimal(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "-- Animal copy constructor" << std::endl;
    const Animal copiedMeta = Animal(*meta);
    const Animal copiedJ = Animal(*j);
    const Animal copiedI = Animal(*i);
    std::cout << copiedMeta.getType() << " " << std::endl;
    std::cout << copiedJ.getType() << " " << std::endl;
    std::cout << copiedI.getType() << " " << std::endl;
    copiedJ.makeSound();
    copiedI.makeSound();
    copiedMeta.makeSound();

    std::cout << "-- Animal default constructor" << std::endl;
    Animal assignableMeta;
    Animal assignableJ;
    Animal assignableI;

    std::cout << "-- Animal assignment operator" << std::endl;
    assignableMeta = copiedMeta;
    assignableJ = copiedJ;
    assignableI = copiedI;
    std::cout << assignableMeta.getType() << " " << std::endl;
    std::cout << assignableJ.getType() << " " << std::endl;
    std::cout << assignableI.getType() << " " << std::endl;
    assignableJ.makeSound();
    assignableI.makeSound();
    assignableMeta.makeSound();

    // below code is compile error.
    // Animal copiedDog = Dog(*j);
    // Animal copiedCat = Dog(*i);

    std::cout << "-- destructor with delete" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "-- Dog default constructor" << std::endl;
    Dog dog;
    std::cout << dog.getType() << " " << std::endl;
    dog.makeSound();

    std::cout << "-- Dog copy constructor" << std::endl;
    Dog copiedDog(dog);
    std::cout << copiedDog.getType() << " " << std::endl;
    copiedDog.makeSound();

    std::cout << "-- Dog assignment operator" << std::endl;
    Dog assignableDog;
    assignableDog = copiedDog;
    std::cout << assignableDog.getType() << " " << std::endl;
    assignableDog.makeSound();

    std::cout << "-- Cat default constructor" << std::endl;
    Cat cat;
    std::cout << cat.getType() << " " << std::endl;
    cat.makeSound();

    std::cout << "-- Cat copy constructor" << std::endl;
    Cat copiedCat(cat);
    std::cout << copiedCat.getType() << " " << std::endl;
    copiedCat.makeSound();

    std::cout << "-- Cat assignment operator" << std::endl;
    Cat assignableCat;
    assignableCat = copiedCat;
    std::cout << assignableCat.getType() << " " << std::endl;
    assignableCat.makeSound();
    std::cout << "-- destructor" << std::endl;
}

void testWrongCat(void)
{
    std::cout << "-- WrongClass test --" << std::endl;
    WrongCat tiger;
    WrongAnimal *animal = &tiger;
    WrongAnimal someAnimal;

    animal->makeSound();
    someAnimal.makeSound();
}
