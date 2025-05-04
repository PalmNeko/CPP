#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point
{
    // variables
    public:
    private:
        const Fixed x;
        const Fixed y;
    // functions
    public:
        // special member functions
        Point(void); // default constructor
        Point(const Point& point); // copy constructor
        Point(const float x, const float y);
        Point(const Fixed& x, const Fixed& y);
        ~Point(void); // destructor
        // others
        const Fixed& getX(void) const;
        const Fixed& getY(void) const;
        int isBelowLine(const Point& a, const Point& b) const;
        void output(std::ostream& o = std::cout) const;
        static bool isTriangle(const Point& a, const Point& b, const Point& c);
        // operators
        Point& operator=(const Point& point); // copy assignment operator
        Point operator-(const Point& point) const;
        bool operator==(const Point& point) const;
    private:
};

std::ostream& operator<<(std::ostream &o, const Point& rhs);

#endif
