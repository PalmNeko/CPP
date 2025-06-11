#include "MutantStack.hpp"
#include <stack>
#include <iostream>

template <class T>
void push_wrap(MutantStack<T> &stack, T value);

template <class T>
void pop_wrap(MutantStack<T> &stack);

int main()
{
    MutantStack<int> mstack;
    push_wrap(mstack, 5);
    push_wrap(mstack, 17);
    std::cout << "top: " << mstack.top() << std::endl;
    pop_wrap(mstack);
    std::cout << "size: " << mstack.size() << std::endl;
    push_wrap(mstack, 3);
    push_wrap(mstack, 5);
    push_wrap(mstack, 737);
    //[...]
    push_wrap(mstack, 0);
    int index;
    index = 0;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << "[" << index << "]: " << *it << std::endl;
        ++it;
        ++index;
    }
    std::stack<int> s(mstack);
    std::cout << "::stack.top: " << s.top() << std::endl;
    std::stack<int> t;
    t = s;
    std::cout << "::stack.top: " << t.top() << std::endl;
    return 0;
}

template <class T>
void push_wrap(MutantStack<T> &stack, T value)
{
    std::cout << "push: " << value << std::endl;
    stack.push(value);
}


template <class T>
void pop_wrap(MutantStack<T> &stack)
{
    T value;

    value = stack.top();
    std::cout << "pop: " << value << std::endl;
    stack.pop();
}
