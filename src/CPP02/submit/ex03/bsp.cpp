#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    const Point triangle[] = {a, b, c};

    if (Point::isTriangle(a, b, c) == false)
        return (false);
    for (int i = 0; i < 3; i++)
    {
        const Point &point1 = triangle[(i + 1) % 3];
        const Point &point2 = triangle[(i + 2) % 3];
        if (triangle[i].isBelowLine(point1, point2) != point.isBelowLine(point1, point2))
            return (false);
    }
    return (true);
}
