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

template <typename T, typename InputIterator>
std::vector<T> pmergeme(InputIterator first, InputIterator last)
{

	if (first == last)
		return std::vector<T>();
	
	InputIterator it;
	InputIterator ite;
    // 中身を出力する。
    it = first;
    ite = last;
    while (it != ite)
    {
        std::cout << *it << " " << std::endl;
        it++;
    }
    std::cout << std::endl;

    // pairを格納したコンテナを作る。
	std::vector<Node *> nodes;

	Node *leftovers;
    std::vector<Node *> container;
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
    // イテレータをpmergemeに渡してソートしたものを受け取る。
    // Container sorted = pmergeme(container.begin(), container.end());
    // main chainを作る。
    // 最初の要素のfirstを追加。
    // 残りの要素のsecondを追加。
    // sub chain ?を作る。
    // 全てのfirstを追加。(最初の要素は結局使わない)
    // main chainにsub-chainを2分挿入する。（この際何番目の要素を入れるかはあの数列を使う。）
    // pairになり切らなかった要素をmainchainに追加。
    // 結果を返す。
	return std::vector<T>();
}
#endif // PMERGE_ME_HPP
