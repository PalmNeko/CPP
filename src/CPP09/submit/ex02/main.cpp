#include "PmergeMe.hpp"
#include "Node.hpp"
#include <vector>
#include <cstdlib>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc == 1)
        return (0);
    std::vector<int> values(argc - 1);
    //TODO エラーチェックしないとダメよ。値の範囲。数字以外の文字が含まれるかどうか。オーバーフロー
    std::transform(argv + 1, argv + argc, values.begin(), std::atoi);
    std::vector<Node *> nodes(argc - 1);
    std::transform(values.begin(), values.end(), nodes.begin(), static_cast<Node *(*)(int)>(Node::create));
    PmergeMe::Container res;
    res = PmergeMe::pmergeme(nodes.begin(), nodes.end());
    std::cout << "compcnt: " << Node::comp_count << std::endl;
    PmergeMe::print(res.begin(), res.end());
    PmergeMe::destroy_pairs(nodes.begin(), nodes.end());
    return (0);
}
