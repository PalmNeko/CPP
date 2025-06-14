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

    // 中身を出力する。
	print(first, last);
    // pairを格納したコンテナを作る。
	Node *leftovers;
    Container pairs;
	pairs = create_pairs(first, last, &leftovers);
    // イテレータをpmergemeに渡してソートしたものを受け取る。
	pmergeme(pairs.begin(), pairs.end());
    // Container sorted = pmergeme(container.begin(), container.end());
    // main chainを作る。
    // 最初の要素のfirstを追加。
    // 残りの要素のsecondを追加。
    // sub chain ?を作る。
    // 全てのfirstを追加。(最初の要素は結局使わない)
    // main chainにsub-chainを2分挿入する。（この際何番目の要素を入れるかはあの数列を使う。）
    // pairになり切らなかった要素をmainchainに追加。
	// 終了処理
	destroy_pairs(pairs.begin(), pairs.end());
    // 結果を返す。
	return Container();
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
