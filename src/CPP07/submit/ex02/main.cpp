#include "Array.hpp"
#include "cstdlib"
#include <iostream>

#define MAX_VAL 750

template <typename T> void testEqual(const Array<T> &a1, const Array<T> &a2);

int main(int, char **)
{
    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // SCOPE
    {
        Array<int> tmp = numbers;
        testEqual(numbers, tmp);
        Array<int> test(tmp);
        testEqual(test, tmp);
        numbers[3] = 12;
        testEqual(test, tmp);
    }

    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return 0;
}

template <typename T> void testEqual(const Array<T> &a1, const Array<T> &a2)
{
    if (a1.size() != a2.size())
    {
        std::cout << "not equal array" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < a1.size(); i++)
    {
        if (a1[i] != a2[i])
        {
            std::cout << "[" << i << "]" << ": not much value a1: " << a1[i]
                      << " a2: " << a2[i] << std::endl;
            return;
        }
    }
    return;
}
