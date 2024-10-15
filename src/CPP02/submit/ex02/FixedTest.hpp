#ifndef FIXED_TEST_HPP
# define FIXED_TEST_HPP

# include "Fixed.hpp"

class FixedTest
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        FixedTest(void); // default constructor
        FixedTest(const FixedTest& fixedTest); // copy constructor
        ~FixedTest(void); // destructor
        // others
        bool testBinaryArithmeticOperators(void);
        bool testBinaryComparisonOperator(void);
        bool testUnaryOperator(void);
        bool testMax(void);
        bool testMin(void);
        // operators
        FixedTest& operator=(const FixedTest& fixedTest); // copy assignment operator
    private:
};

#endif
