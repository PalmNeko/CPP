#include "utils.hpp"
#include <limits>
#include <cmath>

namespace ft
{
    // 後でクラスに戻す
    // ( 2^(no + 1) + (-1)^(no)) / 3
    // https://seriouscomputerist.atariverse.com/media/pdf/book/Art%20of%20Computer%20Programming%20-%20Volume%203%20(Sorting%20&%20Searching).pdf
    // ref: p.185 (13)
    size_t gen_sort_numbers(size_t no)
    {
        if (no >= 32)
            return std::numeric_limits<int>::max();
        double value = (std::pow(2, no + 1) + std::pow(-1, no)) / 3;
        if (value > std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        return static_cast<size_t>(value);
    }
}
