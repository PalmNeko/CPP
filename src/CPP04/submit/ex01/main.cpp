#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

void testAnimals(int N);

int main(void)
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    testAnimals(4);
    return 0;
}

void testAnimals(int N)
{
    Animal* animals[N];

    if (N % 2 == 1)
        throw std::runtime_error("You have to set multiple of 2");
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
