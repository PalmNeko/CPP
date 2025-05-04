#include "Point.hpp"

/*
 * special member functions
 */
Point::Point(void)
{}

Point::Point(const Point& point)
    : x(point.x),
    y(point.y)
{}

Point::Point(const float x, const float y)
    : x(x),
    y(y)
{}

Point::Point(const Fixed& x, const Fixed& y)
    : x(x),
    y(y)
{}

Point::~Point(void)
{}

/*
 * others: public
 */
const Fixed& Point::getX(void) const
{
    return (this->x);
}

const Fixed& Point::getY(void) const
{
    return (this->y);
}

int Point::isBelowLine(const Point& a, const Point& b) const
{
    Fixed deltaX = b.x - a.x;
    Fixed deltaY = b.y - a.y;

     // 線上の点を調べるときは他の点との位置によって線の上側か下側かが変わり曖昧になるが、含めることとする。
    if (deltaX == 0)
    {
        if (this->x > a.x)
            return (1);
        else if (this->x == a.x)
            return (0);
        else
            return (-1);
    }
    if (deltaY == 0)
    {
        if (this->y > a.y)
            return (1);
        else if (this->y == a.y)
            return (0);
        else if (this->y < a.y)
            return (-1);
    }
    Fixed inclination = deltaY / deltaX;
    Fixed rvalue = (inclination) * (this->x - a.x) + a.y;
    if (this->y > rvalue)
        return (1);
    else if (this->y == rvalue)
        return (0);
    else if (this->y < rvalue)
        return (-1);
    return (0);
}

void Point::output(std::ostream& o) const
{
    o << this->getX() << "," << this->getY();
}

bool Point::isTriangle(const Point& a, const Point& b, const Point& c)
{
    if (a == b || b == c || c == a)
        return (false);
    const Point movB(b - a);
    const Point movC(c - a);
    if (movB.getX() * movC.getY() == movB.getY() * movC.getX())
        return (false);
    return (true);
}

/*
 * operators
 */
Point& Point::operator=(const Point& point)
{
    if (this != &point)
    {
    }
    return *this;
}

Point Point::operator-(const Point& point) const
{
    return (Point(this->getX() - point.getX(), this->getY() - point.getY()));
}

bool Point::operator==(const Point& point) const
{
    return (this->getX() == point.getX() && this->getY() == point.getY());
}

std::ostream& operator<<(std::ostream &o, const Point& rhs)
{
    rhs.output(o);
    return o;
}
