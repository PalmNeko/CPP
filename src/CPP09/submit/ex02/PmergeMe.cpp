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

Container pmergeme(std::vector<Node *>::iterator first, std::vector<Node *>::iterator last)
{

	if (first == last)
		return Container();

	InputIterator it;
	InputIterator ite;
    // 中身を出力する。
    it = first;
    ite = last;
    while (it != ite)
    {
        std::cout << (*it)->get_larger_value() << " ";
        it++;
    }
    std::cout << std::endl;

    // pairを格納したコンテナを作る。
	Container nodes;

	Node *leftovers;
    Container container;
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
            container.push_back(newNode);
        }
        else
            leftovers = *(--it);
        it++;
    }
    (void)leftovers;
    // イテレータをpmergemeに渡してソートしたものを受け取る。
    // Container sorted = pmergeme(container.begin(), container.end());
    // main chainを作る。
    // 最初の要素のfirstを追加。
    // 残りの要素のsecondを追加。
    // sub chain ?を作る。
    // 全てのfirstを追加。(最初の要素は結局使わない)
    // main chainにsub-chainを2分挿入する。（この際何番目の要素を入れるかはあの数列を使う。）
    // pairになり切らなかった要素をmainchainに追加。
	// 終了処理
	it = container.begin();
	ite = container.end();
	while (it != ite)
	{
		delete *it;
		it++;
	}
    // 結果を返す。
	return Container();
}
