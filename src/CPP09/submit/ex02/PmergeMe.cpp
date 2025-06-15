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

// vector用とlist用で分けれると良き。
PmergeMe::InputIterator PmergeMe::at(Container &container, int index)
{
	InputIterator it;
	int times;

	if (container.size() - index > container.size() / 2)
	{
		it = container.begin();
		times = index;
		while (times > 0)
		{
			it++;
			times--;
		}
		return it;
	}
	else
	{
		it = container.end();
		times = container.size() - index;
		while (times > 0)
		{
			it--;
			times--;
		}
		return it;
	}
}

void PmergeMe::insertAll(Container &mainchain, Container &subchain)
{
	size_t insert_times;
	size_t inserted_index;
	size_t max_index;

	insert_times = 0;
	max_index = subchain.size() - 1;
	inserted_index = -1;
	if (subchain.size() > 0)
	{
		insert_times++;
		mainchain.insert(mainchain.begin(), *subchain.begin());
		inserted_index++;
	}

	while (inserted_index < max_index)
	{
		size_t index;
		InputIterator it;
		InputIterator ite;

		insert_times++;
		index = calc_index(insert_times);
		if (index > subchain.size() - 1)
			index = subchain.size() - 1;
		it = at(subchain, index);
		ite = at(subchain, inserted_index);
		while (it != ite)
		{
			binary_insert(mainchain, *it);
			it--;
		}
		inserted_index = index;
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

PmergeMe::Container PmergeMe::jacob_merge(Container &sorted_pairs)
{
	Container mainchain;

	if (sorted_pairs.size() == 0)
		return mainchain;

	InputIterator it = sorted_pairs.begin();
	InputIterator ite = sorted_pairs.end();

	// 一旦先頭2つを入れる。
	InputIterator insertItEnd;
	int sort_times = 0;
	mainchain.push_back((*it)->getSmaller());
	mainchain.push_back((*it)->getLarger());
	insertItEnd = it;
	it++;
	sort_times++;

	while (it != ite)
	{
		InputIterator sortItEnd;

		sortItEnd = sorted_pairs.begin();
		size_t sortIndexEnd = calc_index(sort_times);
		if (sortIndexEnd > sorted_pairs.size())
			sortIndexEnd = sorted_pairs.size();
		std::advance(sortItEnd, sortIndexEnd);
		InputIterator insertIt;

		insertIt = insertItEnd;
		while (it != sortItEnd)
		{
			mainchain.push_back((*it)->getLarger());
			insertIt = it; // iterator of previous sortItEnd iterator
			it++;
		}

		Stack tmpHolder;
		while (insertIt != insertItEnd)
		{
			Node *insertValue = (*insertIt)->getSmaller();
			insertIt--;
			Node *rangeLastValue = (*insertIt)->getLarger();
			while (mainchain.back() != rangeLastValue)
			{
				tmpHolder.push(mainchain.back());
				mainchain.pop_back();
			}
			InputIterator insertPos = binary_insert_iterator(mainchain.begin(), mainchain.end(), *insertValue);
			mainchain.insert(insertPos, insertValue);
		}
		while (tmpHolder.size() != 0)
		{
			mainchain.push_back(tmpHolder.top());
			tmpHolder.pop();
		}
		sort_times++;
	}
	return mainchain;
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

	while (sortIt != sortIte)
	{
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
	sortIt = sorted_pairs.begin();
	mainchain.push_back(sorted_pairs.front()->getSmaller());
	mainchain.push_back(sorted_pairs.front()->getLarger());
	sortIt++;

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

		while (mainchain.back() != (*largechainIt))
		{
			mainchain.push_back((*sortIt)->getLarger());
			sortIt++;
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
		while (holdStack.size() != 0)
		{
			mainchain.push_back(holdStack.top());
			holdStack.pop();
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
