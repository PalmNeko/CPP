#include "Point.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

#define FIXED_BIT 0.00390625f
#define FIXED_MAX (Fixed(8388607) + Fixed(0.99609375f))
#define FIXED_MIN -8388608
#define ROOT_2 1.41421356237f
bool bsp(Point const a, Point const b, Point const c, Point const point);
void useBspAndLogging(Point const & a, Point const & b, Point const & c, Point const & point, std::ostringstream& oss, bool toBe);
void insideTest(void);
void outsideTest(void);
void boundaryTest(void);
void irregularTest(void);

#include <bitset>
#include <climits>

int main(void)
{
    Fixed::setDebugStream(std::cerr);
    std::cout <<
        std::endl <<
        "+-------------+\n"
        "+     bsp     +\n"
        "+-------------+\n" <<
        std::endl;
    insideTest();
    outsideTest();
    boundaryTest();
    irregularTest();
    return 0;
}

#include <iomanip>
void insideTest(void)
{
    std::cout << "inside test" << std::endl;
    std::ostringstream oss;

    useBspAndLogging(Point(055.003f, 102.003f), Point(190.003f, 147.003f), Point(121.003f, 207.003f), Point(069.003f, 116.003f), oss, true);
    useBspAndLogging(Point(375.003f, 126.003f), Point(281.003f, 127.003f), Point(281.003f, 027.003f), Point(347.003f, 117.003f), oss, true);
    useBspAndLogging(Point(465.003f, 072.003f), Point(837.003f, 314.003f), Point(860.003f, 083.003f), Point(846.003f, 097.003f), oss, true);
    useBspAndLogging(Point(198.003f, 294.003f), Point(306.003f, 296.003f), Point(381.003f, 223.003f), Point(300.003f, 285.003f), oss, true);
    useBspAndLogging(Point(391.003f, 326.003f), Point(713.003f, 311.003f), Point(374.003f, 488.003f), Point(399.003f, 331.003f), oss, true);
    useBspAndLogging(Point(162.003f, 397.003f), Point(061.003f, 621.003f), Point(551.003f, 624.003f), Point(197.003f, 526.003f), oss, true);
    std::string pointList = oss.str();

    pointList = pointList.substr(0, pointList.size() - 1);
    std::cout << "view: https://palmneko.github.io/view-triangle-and-dot/?pos=" << pointList << std::endl;
    return ;
}

void outsideTest(void)
{
    std::cout << "outside test" << std::endl;
    std::ostringstream oss;

    useBspAndLogging(Point(168, 111), Point(168, 275), Point(324, 276), Point(285, 226), oss, false);
    useBspAndLogging(Point(181, 105), Point(490, 26), Point(364, 303), Point(483, 55), oss, false);
    useBspAndLogging(Point(485, 66), Point(437, 165), Point(486, 162), Point(474, 69), oss, false);
    useBspAndLogging(Point(460, 427), Point(460, 179), Point(298, 426), Point(480, 178), oss, false);
    useBspAndLogging(Point(507, 18), Point(468, 389), Point(732, 393), Point(576, 401), oss, false);
    useBspAndLogging(Point(528, 38), Point(677, 31), Point(624, 181), Point(552, 83), oss, false);
    useBspAndLogging(Point(695, 37), Point(829, 187), Point(636, 185), Point(667, 80), oss, false);
    useBspAndLogging(Point(269, 577), Point(491, 575), Point(713, 406), Point(597, 504), oss, false);
    useBspAndLogging(Point(633, 201), Point(743, 384), Point(1002, 510), Point(685, 308), oss, false);
    std::string pointList = oss.str();

    pointList = pointList.substr(0, pointList.size() - 1);
    std::cout << "view: https://palmneko.github.io/view-triangle-and-dot/?pos=" << pointList << std::endl;
}

void boundaryTest(void)
{
    std::cout << "boundary test" << std::endl;
    std::ostringstream oss;
    float unit;

    unit = FIXED_BIT;
    useBspAndLogging(Point(0, 0), Point(unit, unit), Point(unit, 0), Point((2 * unit / 3), unit / 3), oss, false);
    unit = FIXED_BIT * 2;
    useBspAndLogging(Point(0, 0), Point(unit, unit), Point(unit, 0), Point((2 * unit / 3), unit / 3), oss, false);
    unit = FIXED_BIT * 3;
    useBspAndLogging(Point(0, 0), Point(unit, unit), Point(unit, 0), Point((2 * unit / 3), unit / 3), oss, false); // 手計算上は中に入っているが、三角形かどうかを判定する際に、アンダーフローしているため、false
    unit = FIXED_BIT * 3000;
    useBspAndLogging(Point(0, 0), Point(unit, unit), Point(unit, 0), Point((2 * unit / 3), unit / 3), oss, true);
    useBspAndLogging(Point(10, 10), Point(20, 20), Point(20 - FIXED_BIT, 10), Point(20, 10 + FIXED_BIT), oss, false);
    useBspAndLogging(Point(10 + 15, 10), Point(20 + 15, 20), Point(20 + 15 + FIXED_BIT, 10), Point(20 + 15, 10 + FIXED_BIT), oss, true);
    useBspAndLogging(Point(10 + 30, 10), Point(20 + 30, 20), Point(20 + 30, 10), Point(20 + 30, 10 + FIXED_BIT), oss, false);
    useBspAndLogging(Point(10, 40), Point(10 + 10, 40), Point(10, 40 + 10), Point(10 + 5 - FIXED_BIT, 40 + 5 - FIXED_BIT), oss, true); // 線の真上だが、
    useBspAndLogging(Point(10 + 20, 40), Point(10 + 10 + 20, 40), Point(10 + 20, 40 + 10), Point(10 + 5  + 20, 40 + 5), oss, false);
    std::cout << Fixed(-1) * Fixed(14.99609375f) + Fixed(60) << std::endl;
    std::string pointList = oss.str();

    pointList = pointList.substr(0, pointList.size() - 1);
    std::cout << "view: https://palmneko.github.io/view-triangle-and-dot/?pos=" << pointList << std::endl;
}

void irregularTest(void)
{
    std::cout << "irregular test" << std::endl;
    std::ostringstream oss;

    useBspAndLogging(Point(100, 100), Point(100, 100), Point(100, 100), Point(100, 100), oss, false);
    useBspAndLogging(Point(100, 100 + 10), Point(100, 100 + 10), Point(100, 100 + 10), Point(100 + 10, 100 + 10), oss, false);
    useBspAndLogging(Point(100, 200), Point(200, 200), Point(300, 200), Point(150, 200), oss, false);
    useBspAndLogging(Point(100, 250), Point(200, 250), Point(300, 250), Point(350, 250), oss, false);
    // 100倍しないと、傾きを出すときにアンダーフローして計算が狂う FIXED_BIT / 100
    useBspAndLogging(Point(100, 300), Point(200, 300 + 100 * FIXED_BIT), Point(300, 300), Point(150, 300), oss, true);
    useBspAndLogging(Point(100, 350), Point(200, 350 + 100 * FIXED_BIT), Point(300, 350), Point(350, 350), oss, false);

    std::string pointList = oss.str();

    pointList = pointList.substr(0, pointList.size() - 1);
    std::cout << "view: https://palmneko.github.io/view-triangle-and-dot/?pos=" << pointList << std::endl;
}

// https://palmneko.github.io/view-triangle-and-dot/?pos=0.550781,1.019531.89844,1.468751.21094,2.070310.691406,1.16016,3.75,1.261722.80859,1.269532.80859

void useBspAndLogging(Point const & a, Point const & b, Point const & c, Point const & point, std::ostringstream& oss, bool toBe)
{
    bool result;
    static int testNo;

    std::cout << "No: " << testNo++ << std::endl;
    std::cout << std::setw(22) << "target point(x, y): " << point << std::endl;
    std::cout << std::setw(22) << "a: " << a << std::endl;
    std::cout << std::setw(22) << "b: " << b << std::endl;
    std::cout << std::setw(22) << "c: " << c << std::endl;
    result = bsp(a, b, c, point);
    std::cout << std::setw(22) << "inside the triangle: " << (result ? "true" : "false") << std::endl;
    std::cout << std::setw(22) << "test result: " << (result == toBe ? "Success" : "Failed") << std::endl;
    oss << a << "," << b << "," << c << "," << point << ",";
}
