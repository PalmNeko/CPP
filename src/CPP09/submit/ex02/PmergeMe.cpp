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
	*this = other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
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

	Container mainchain = jacob_merge(sorted, leftovers);

	destroy_pairs(pairs.begin(), pairs.end());
	return mainchain;
}

void PmergeMe::print(InputIterator first, InputIterator last, bool colored)
{
	InputIterator it;
	InputIterator ite;
    it = first;
    ite = last;
	int i = 0;
    while (it != ite)
    {
		if (i % 2 == 0 && colored)
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
	if (colored)
		std::cout << "\e[m";

    std::cout << std::endl;
}

PmergeMe::Container PmergeMe::create_pairs(InputIterator first, InputIterator last, Node **leftovers)
{
	Container pairs;
	InputIterator it;
	InputIterator ite;
	size_t index;
	Node *a;
	Node *b;

	*leftovers = NULL;
    it = first;
    ite = last;
	index = 0;
    while (it != ite)
    {
		if (index % 2 == 0)
			a = *it;
		else
		{
			b = *it;
			try
			{
				Node *newNode = Node::create(a, b);
            	pairs.push_back(newNode);
			}
			catch (const std::exception &e)
			{
				destroy_pairs(pairs.begin(), pairs.end());
				throw ;
			}
		}
        it++;
		index++;
    }
	if (index % 2 == 1)
		*leftovers = a;
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
size_t PmergeMe::gen_sort_numbers(size_t no)
{
	if (no >= 32)
		return std::numeric_limits<int>::max();
	double value = (std::pow(2, no + 1) + std::pow(-1, no)) / 3;
	if (value > std::numeric_limits<int>::max())
	    return std::numeric_limits<int>::max();
	return static_cast<int>(value);
}

PmergeMe::InputIterator PmergeMe::at(InputIterator it, size_t now, size_t at)
{
	std::advance(it, at - now);
	return it;
}

PmergeMe::InputIterator PmergeMe::next(InputIterator it, size_t index)
{
	std::advance(it, index);
	return it;
}

PmergeMe::Container PmergeMe::jacob_merge(PmergeMe::Container &sorted_pairs, Node *leftovers)
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

	Stack holdStack;
	int sort_times = 1;

	size_t sortIndex;
	InputIterator largechainIt;
	InputIterator smallchainIt;

	sortIndex = 0;
	while (sortIndex != smallchain.size() - 1)
	{
		size_t smallIndex;
		size_t largeIndex;

		sort_times++;
		sortIndex = std::min(gen_sort_numbers(sort_times) - 1, smallchain.size() - 1); // 2 -> 3
		smallIndex = sortIndex;

		InputIterator smallchainIte;
		smallchainIt = next(smallchain.begin(), smallIndex);
		smallchainIte = next(smallchain.begin(), gen_sort_numbers(sort_times - 1) - 1);
		largeIndex = std::min(smallIndex, largechain.size() - 1);
		largechainIt = PmergeMe::next(largechain.begin(), largeIndex);
		if (holdStack.size() != 0)
		{
			while (mainchain.back() != (*largechainIt))
			{
				mainchain.push_back(holdStack.top());
				holdStack.pop();
			}
		}
		while (smallchainIt != smallchainIte)
		{

			while (mainchain.back() != (*largechainIt))
			{
				holdStack.push(mainchain.back());
				mainchain.pop_back();
			}
			if (smallIndex == largeIndex)
			{
				holdStack.push(mainchain.back());
				mainchain.pop_back();
			}
			binary_insert(mainchain, *smallchainIt);
			smallchainIt--;
			smallIndex--;
			largeIndex = std::min(smallIndex, largechain.size() - 1);
			largechainIt = PmergeMe::next(largechain.begin(), largeIndex);
		}
	}
	while (holdStack.size() != 0)
	{
		mainchain.push_back(holdStack.top());
		holdStack.pop();
	}
	return mainchain;
}

PmergeMe::InputIterator PmergeMe::binary_insert_iterator(InputIterator first, InputIterator last, const Node &value)
{
	if (std::distance(first, last) == 0)
		return first;
	size_t low = 0;
	size_t mid;
	size_t high = std::distance(first, last);

	InputIterator midIt;

	while (low < high)
	{
		mid = (low + high) / 2;
		midIt = first;
		std::advance(midIt, mid);
		if (value < *(*midIt))
			high = mid;
		else
			low = mid + 1;
	}
	midIt = first;
	std::advance(midIt, low);
	return midIt;
}

void PmergeMe::binary_insert(Container &container, Node *value)
{
	if (value == NULL)
		return ;
	InputIterator pos = binary_insert_iterator(container.begin(), container.end(), *value);
	container.insert(pos, value);
}
