#ifndef EASYFIND__HPP
#define EASYFIND__HPP

#include <stack>

// return true on found. return false on not found.
template <typename T> bool easyfind(T &intContainer, int findValue);
template <> bool easyfind<std::stack<int> >(std::stack<int> &intContainer, int findValue);
template <> bool easyfind<std::queue<int> >(std::queue<int> &intContainer, int findValue);

template <typename T> bool easyfindWithContainerAdapter(T &intContainer, int findValue);

#include "easyfind.tpp"

#endif // EASYFIND__HPP
