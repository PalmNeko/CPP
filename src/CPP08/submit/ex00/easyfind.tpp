
#include <algorithm>
#include <stack>
#include <queue>

template <typename T> bool easyfind(T &intContainer, int findValue)
{
    typename T::const_iterator it
        = std::find(intContainer.begin(), intContainer.end(), findValue);

    return (it != intContainer.end());
}
