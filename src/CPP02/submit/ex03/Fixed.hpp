#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
# include <iostream>

class Fixed
{
    // variables
    public:
    private:
        int value;
        static const int fractionalBitNum = 8;
        static std::ostream *o;
    // functions
    public:
        // special member functions
        Fixed(void);               // default constructor
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed); // copy constructor
        ~Fixed(void);              // destructor
        // others
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        void output(std::ostream& o = std::cout) const;
        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static void setDebugStream(std::ostream& o);
        // operators
        Fixed &operator=(const Fixed &fixed); // copy assignment operator
        bool operator<(const Fixed &fixed) const;
        bool operator>(const Fixed &fixed) const;
        bool operator<=(const Fixed &fixed) const;
        bool operator>=(const Fixed &fixed) const;
        bool operator==(const Fixed &fixed) const;
        bool operator!=(const Fixed &fixed) const;
        Fixed operator+(const Fixed &fixed) const;
        Fixed operator-(const Fixed &fixed) const;
        Fixed operator*(const Fixed &fixed) const;
        Fixed operator/(const Fixed &fixed) const;
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
    private:
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif
