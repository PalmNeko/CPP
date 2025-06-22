#include "PmergeMeResult.hpp"

PmergeMeResult::PmergeMeResult() {}

PmergeMeResult::~PmergeMeResult() {}

PmergeMeResult &PmergeMeResult::operator=(const PmergeMeResult &rhs)
{
    if (this != &rhs)
    {
        _values = rhs._values;
        _spent = rhs._spent;
        _compcnt = rhs._compcnt;
    }
    return *this;
}

const std::vector<int> &PmergeMeResult::getValues() const
{
    return _values;
}

clock_t PmergeMeResult::getSpent() const
{
    return _spent;
}

int PmergeMeResult::getCompcnt() const
{
    return _compcnt;
}
