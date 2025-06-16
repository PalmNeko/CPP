#ifndef PMERGE_ME_RESULT_HPP
#define PMERGE_ME_RESULT_HPP

#include <ctime>
#include <vector>

class PmergeMeResult
{
    private:
        std::vector<int> _values;
        clock_t _spent;
        int _compcnt;

    public:
        template <typename InputIterator>
        PmergeMeResult(InputIterator first, InputIterator last, clock_t spent, int compcnt);
        ~PmergeMeResult();
        PmergeMeResult();
        PmergeMeResult &operator=(const PmergeMeResult &rhs);

        const std::vector<int> &getValues() const;
        clock_t getSpent() const;
        int getCompcnt() const;
};

template <typename InputIterator>
PmergeMeResult::PmergeMeResult(InputIterator first,
                               InputIterator last,
                               clock_t spent,
                               int compcnt)
    : _spent(spent)
    , _compcnt(compcnt)
{
    while (first != last)
    {
        _values.push_back((*first)->get_larger_value());
        first++;
    }
}

#endif // PMERGE_ME_RESULT_HPP
