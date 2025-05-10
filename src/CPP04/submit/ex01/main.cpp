#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void testAnimals(void);

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    testAnimals();
    return 0;
}

void testAnimals(void)
{
    const int N = 4;
    Animal* animals[N];

    int new_cnt;
    new_cnt = 0;
    try {
        while (new_cnt < N / 2)
        {
            animals[new_cnt] = new Cat();
            new_cnt++;
        }
        while (new_cnt < N)
        {
            animals[new_cnt] = new Dog();
            new_cnt++;
        }
    }
    catch (const std::bad_alloc& e)
    {}
    while (new_cnt-- > 0)
        delete animals[new_cnt];
}
