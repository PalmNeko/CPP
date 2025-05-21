#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <vector>

template <typename T> void testEasyFind(int *begin, int *end);
template <> void testEasyFind<std::stack<int> >(int *begin, int *end);
template <> void testEasyFind<std::queue<int> >(int *begin, int *end);

template <typename T> void testEasyFindWithContainerAdapter(int *begin, int *end);

int main(void)
{
    int array[] = {5, 2, 7, 10, 3, 2, 4};
    int *begin = array;
    int *end = array + sizeof(array);

    testEasyFind<std::list<int> >(begin, end);
    testEasyFind<std::vector<int> >(begin, end);
    testEasyFind<std::deque<int> >(begin, end);
	testEasyFind<std::set<int> >(begin, end);

    return (0);
}

template <typename T> void testEasyFind(int *begin, int *end)
{
    T container(begin, end);

    std::cout << std::boolalpha;
    std::cout << "find value 2: " << easyfind<T>(container, 2) << std::endl;
    std::cout << "find value 11: " << easyfind<T>(container, 11) << std::endl;
    std::cout << "find value 4: " << easyfind<T>(container, 11) << std::endl;
}
