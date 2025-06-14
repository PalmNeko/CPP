#include "PmergeMe.hpp"
#include "Node.hpp"
#include <vector>

int main(void)
{
    const int size = 10;
    int values[size] = {7, 5, 4, 1, 6, 3, 9, 10, 8, 2};

    std::vector<Node *> a;
    for (int *it = (int *)values; it != values + size; it++)
        a.push_back(new Node(*it));
    PmergeMe::Container res;
    res = PmergeMe::pmergeme(a.begin(), a.end());
    PmergeMe::print(res.begin(), res.end());
    PmergeMe::destroy_pairs(a.begin(), a.end());
    return (0);
}
