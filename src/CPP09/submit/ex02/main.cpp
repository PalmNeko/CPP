#include "PmergeMe.hpp"
#include "Node.hpp"
#include <vector>

int main(void)
{
    int values[] = {2, 5, 3, 1, 4};
    const int size = sizeof(values) / sizeof(values[0]);

    std::vector<Node *> a;
    for (int *it = (int *)values; it != values + size; it++)
        a.push_back(new Node(*it));
    PmergeMe::Container res;
    res = PmergeMe::pmergeme(a.begin(), a.end());
    std::cout << "compcnt: " << Node::comp_count << std::endl;
    PmergeMe::print(res.begin(), res.end());
    PmergeMe::destroy_pairs(a.begin(), a.end());
    return (0);
}
