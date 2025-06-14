#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include "Node.hpp"

#include <iostream>
#include <vector>

class PmergeMe
{
    private:
    protected:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        virtual ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);

    public:
};

// templates header
typedef std::vector<Node *>::iterator InputIterator;
typedef std::vector<Node *> Container;
Container pmergeme(InputIterator first, InputIterator last);

#endif // PMERGE_ME_HPP
