#include "FixedTest.hpp"
#include "Fixed.hpp"
#include <cassert>

/*
 * special member functions
 */
FixedTest::FixedTest(void)
{}

FixedTest::FixedTest(const FixedTest& fixedTest)
{(void)fixedTest;}

FixedTest::~FixedTest(void)
{}

/*
 * others: public
 */
#include <iostream>
#include <iomanip>
bool FixedTest::testBinaryArithmeticOperators(void)
{
    const Fixed lowest = Fixed(0.00390625f);
    const Fixed high = Fixed(0x20000000 >> 8);
    assert(Fixed(0) + Fixed(10) == Fixed(10));
    assert(Fixed(142.00390625f) + Fixed(781.00390625f) == Fixed(923.0078125f));
    assert(Fixed(781.00390625f) - Fixed(142.00390625f) == Fixed(639));
    assert(Fixed(142.00390625f) - Fixed(781.00390625f) == Fixed(-639));
    assert(Fixed(5.05f) * Fixed(2) == Fixed(10.1016f));
    assert((lowest + high).getRawBits() == 0x20000001);
    assert(((lowest + high) * Fixed(2)).getRawBits() == 0x40000002);
    assert(((lowest + high) * Fixed(2.75f)).getRawBits() == 0x58000002); // = 0x20000001 << 1 + 0x20000001 >> 1 + 0x20000001 >> 2
    // assert(Fixed(5.05f) / Fixed(0) == Fixed(2.52734f)); // will Floating point exception
    assert(((lowest + high) * Fixed(2.75f) / Fixed(2)).getRawBits() == 0x58000002 >> 1);
    return (true);
}

bool FixedTest::testBinaryComparisonOperator(void)
{
    // ==
    assert(Fixed(13.1f) == Fixed(13.1f));
    assert(Fixed(-21.2f) == Fixed(-21.2f));
    assert(!(Fixed(-21.2f) == Fixed(-21.1f)));
    assert(!(Fixed(0) == Fixed(-21.1f)));
    // !=
    assert(Fixed(-21.2f) != Fixed(-21.1f));
    assert(Fixed(-19.3f) != Fixed(-19.2f));
    assert(!(Fixed(13.1f) != Fixed(13.1f)));
    assert(!(Fixed(-21.2f) != Fixed(-21.2f)));
    // <
    assert(Fixed(0) < Fixed(0.1f));
    assert(!(Fixed(110.232f) < Fixed(109.423f)));
    // <=
    assert(Fixed(0) <= Fixed(0.1f));
    assert(Fixed(0) <= Fixed(0));
    assert(Fixed(-110.232f) <= Fixed(109.423f));
    assert(!(Fixed(110.232f) <= Fixed(109.423f)));
    assert(!(Fixed(110.233f) <= Fixed(110.232f)));
    // >
    assert(Fixed(342320.2f) > Fixed(283923.342f));
    assert(!(Fixed(58392.47302911113f) > Fixed(483923.342f)));
    // >=
    assert(Fixed(342320.2f) >= Fixed(283923.342f));
    assert(Fixed(3420.2849f) >= Fixed(3420.2849f));
    assert(!(Fixed(58392.47302911113f) >= Fixed(483923.342f)));
    assert(!(Fixed(58392.47302911113f) >= Fixed(58392.87302911113f)));
    return (true);
}

bool FixedTest::testUnaryOperator(void)
{
    assert(++Fixed(0) == Fixed(0.00390625f));
    assert(Fixed(0)++ == Fixed(0));
    assert(--Fixed(0) == Fixed(-0.00390625f));
    assert(Fixed(0)-- == Fixed(0));
    return (true);
}

bool FixedTest::testMax(void)
{
    assert(Fixed::max(Fixed(10.106f), Fixed(0.0078125f)) == Fixed(10.106f));
    assert(Fixed::max(Fixed(0.0078125f), Fixed(10.106f)) == Fixed(10.106f));
    return (true);
}

bool FixedTest::testMin(void)
{
    assert(Fixed::min(Fixed(10.106f), Fixed(0.0078125f)) == Fixed(0.0078125f));
    assert(Fixed::min(Fixed(0.0078125f), Fixed(10.106f)) == Fixed(0.0078125f));
    return (true);
}


/*
 * operators
 */
FixedTest& FixedTest::operator=(const FixedTest& fixedTest)
{
    if (this != &fixedTest)
    {
    }
    return *this;
}

/*
 * others: private
 */
