#include "PmergeMe.hpp"
#include "Node.hpp"
#include <vector>

int main(void)
{
    const int size = 10;
    int values[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<Node *> a;
    for (int *it = (int *)values; it != values + size; it++)
        a.push_back(new Node(*it));
    pmergeme(a.begin(), a.end());
    for (std::vector<Node *>::iterator it = a.begin(); it != a.end(); it++)
        delete *it;
    return (0);
}
