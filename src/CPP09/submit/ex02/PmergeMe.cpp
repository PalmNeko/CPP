#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>
#include <stack>
#include <limits>
#include <cmath>
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
	print(first, last);
	Node *leftovers;
	leftovers = NULL;

    Container pairs;
	pairs = create_pairs(first, last, &leftovers);

    Container sorted;
	sorted = pmergeme(pairs.begin(), pairs.end());

	std::cout << "leftovers: ";
	if (leftovers != NULL)
		std::cout << *leftovers;
	else
		std::cout << leftovers;
	std::cout << " sorted: " ;
	print(sorted.begin(), sorted.end());

	Container mainchain = jacob_merge2(sorted, leftovers);

	destroy_pairs(pairs.begin(), pairs.end());
	std::cout << "size: " << std::distance(first, last) << " cmpcnt: " << Node::comp_count << " mainchain: ";
	print(mainchain.begin(), mainchain.end());
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

// ( 2^(no + 1) + (-1)^(no)) / 3
// https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf
// ref: p.185 (13)
size_t PmergeMe::calc_index(size_t no)
{
	if (no >= 32)
		return std::numeric_limits<int>::max();
	double value = (std::pow(2, no + 1) + std::pow(-1, no)) / 3;
	if (value > std::numeric_limits<int>::max())
	    return std::numeric_limits<int>::max();
	return static_cast<int>(value);
}

PmergeMe::Container PmergeMe::jacob_merge2(PmergeMe::Container &sorted_pairs, Node *leftovers)
{
	Container mainchain;
	Container largechain;
	Container smallchain;

	InputIterator sortIt;
	InputIterator sortIte;

	if (sorted_pairs.size() == 0)
	{
		if (leftovers)
			mainchain.push_back(leftovers);
		return mainchain;
	}
	sortIt = sorted_pairs.begin();
	sortIte = sorted_pairs.end();

	mainchain.push_back(sorted_pairs.front()->getSmaller());
	while (sortIt != sortIte)
	{
		mainchain.push_back((*sortIt)->getLarger());
		largechain.push_back((*sortIt)->getLarger());
		smallchain.push_back((*sortIt)->getSmaller());
		sortIt++;
	}
	if (leftovers != NULL)
		smallchain.push_back(leftovers);
	std::cout << "largechain: ";
	print(largechain.begin(), largechain.end());
	std::cout << "smallchain: ";
	print(smallchain.begin(), smallchain.end());

	Stack holdStack;
	int sort_times = 1;

	size_t sortIndex;
	InputIterator largechainIt;
	InputIterator smallchainIt;

	// std::cout << "start jacob_merge2 - main" << std::endl;
	sortIndex = 0;
	while (sortIndex != smallchain.size() - 1)
	{
		sort_times++;
		sortIndex = calc_index(sort_times) - 1; // 2 -> 3
		if (sortIndex > smallchain.size() - 1)
			sortIndex = smallchain.size() - 1;
		largechainIt = largechain.begin();
		smallchainIt = smallchain.begin();

		std::advance(largechainIt, sortIndex - 1);
		std::advance(smallchainIt, sortIndex);

		if (holdStack.size() != 0)
		{
			while (mainchain.back() != (*largechainIt))
			{
				mainchain.push_back(holdStack.top());
				holdStack.pop();
			}
		}
		while (mainchain.back() != (*largechainIt))
		{
			holdStack.push(mainchain.back());
			mainchain.pop_back();
		}
		InputIterator smallchainIte;
		smallchainIte = smallchain.begin();
		std::advance(smallchainIte, calc_index(sort_times - 1) - 1);
		while (smallchainIt != smallchainIte)
		{
			InputIterator insertPos;

			while (mainchain.back() != *largechainIt)
			{
				holdStack.push(mainchain.back());
				mainchain.pop_back();
			}
			binary_insert(mainchain, *smallchainIt);
			largechainIt--;
			smallchainIt--;
		}
	}
	if (!leftovers)
		mainchain.push_back(largechain.back());
	return mainchain;
}

PmergeMe::InputIterator PmergeMe::binary_insert_iterator(InputIterator first, InputIterator last, const Node &value)
{
	if (std::distance(first, last) == 0)
		return first;
	size_t low = 0;
	size_t mid;
	size_t high = std::distance(first, last) - 1;

	InputIterator midIt;

	while (low != high)
	{
		mid = (low + high) / 2;
		if (mid == low)
			break ;
		midIt = first;
		std::advance(midIt, mid);
		if (*(*midIt) < value)
			low = mid + 1;
		else
			high = mid;
	}
	mid = (low + high) / 2;
	midIt = first;
	std::advance(midIt, mid);
	if (*(*midIt) < value)
		return ++midIt;
	else
		return midIt;
}

void PmergeMe::binary_insert(Container &container, Node *value)
{
	if (value == NULL)
		return ;
	InputIterator pos = binary_insert_iterator(container.begin(), container.end(), *value);
	container.insert(pos, value);
}
