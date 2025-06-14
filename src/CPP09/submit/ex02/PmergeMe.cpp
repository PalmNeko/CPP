#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <list>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
		// assignment logic
	}
	return *this;
}

PmergeMe::Container PmergeMe::pmergeme(InputIterator first, InputIterator last)
{
	if (first == last)
		return Container();

	Node *leftovers;
	leftovers = NULL;

    Container pairs;
	pairs = create_pairs(first, last, &leftovers);

    Container sorted;
	sorted = pmergeme(pairs.begin(), pairs.end());

	Container mainchain = create_mainchain(sorted.begin(), sorted.end());
	Container subchain = create_subchain(sorted.begin(), sorted.end(), &leftovers);

	insertAll(mainchain, subchain);
	destroy_pairs(pairs.begin(), pairs.end());
	return mainchain;
}

void PmergeMe::print(InputIterator first, InputIterator last)
{
	InputIterator it;
	InputIterator ite;
    it = first;
    ite = last;
	int i = 0;
    while (it != ite)
    {
		if (i % 2 == 0)
		{
			if (i % 4 == 0)
				std::cout << "\e[32m";
			else
				std::cout << "\e[34m";
		}
		i++;
        std::cout << (*it)->get_larger_value() << " ";
        it++;
    }
	std::cout << "\e[m";

    std::cout << std::endl;
}

PmergeMe::Container PmergeMe::create_pairs(InputIterator first, InputIterator last, Node **leftovers)
{
	Container pairs;
	InputIterator it;
	InputIterator ite;

	*leftovers = NULL;
    it = first;
    ite = last;
    while (it != ite)
    {
        it++;
        if (it != ite)
        {
            InputIterator first = --it;
            InputIterator second = ++it;
            Node *newNode = Node::create(*first, *second);
            pairs.push_back(newNode);
        }
        else
            *leftovers = *(--it);
        it++;
    }
	return pairs;
}

void PmergeMe::destroy_pairs(InputIterator first, InputIterator end)
{
	InputIterator it = first;
	while (it != end)
	{
		delete *it;
		it++;
	}
}

PmergeMe::Container PmergeMe::create_mainchain(InputIterator first, InputIterator last)
{
	Container mainchain;
	InputIterator it = first;
	InputIterator ite = last;

	while (it != ite)
	{
		mainchain.push_back((*it)->getLarger());
		it++;
	}
	return mainchain;
}

PmergeMe::Container PmergeMe::create_subchain(InputIterator first, InputIterator last, Node **leftovers)
{
	Container subchain;
	InputIterator it = first;
	InputIterator ite = last;

	while (it != ite)
	{
		subchain.push_back((*it)->getSmaller());
		it++;
	}
	if (*leftovers)
		subchain.push_back(*leftovers);
	return subchain;
}

void PmergeMe::insertAll(Container &mainchain, Container &subchain)
{
	InputIterator it = subchain.begin();
	InputIterator ite = subchain.end();

	if (it != ite)
	{
		mainchain.insert(mainchain.begin(), *it);
		it++;
	}
	// ここをヤコブスタールする。
	while (it != ite)
	{
		insert(mainchain, *it);
		it++;
	}
}

void PmergeMe::insert(Container &mainchain, Node *value)
{
	// このインサートを2分探索する
	InputIterator it = mainchain.begin();
	InputIterator ite = mainchain.end();

	if (mainchain.size() == 0)
		mainchain.push_back(value);
	while (it != ite)
	{
		if (*(*it) < *value)
			it++;
		else
		{
			mainchain.insert(it, value);
			return ;
		}
	}
	mainchain.push_back(value);
}

PmergeMe::Container PmergeMe::flatten(InputIterator first, InputIterator last)
{
	Container flatten;

	InputIterator it = first;
	while (it != last)
	{
		flatten.push_back((*it)->getSmaller());
		flatten.push_back((*it)->getLarger());
		it++;
	}
	return flatten;
}
