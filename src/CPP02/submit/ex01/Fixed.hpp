#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>
class Fixed
{
    // variables
    public:
    private:
        int value;
        static const int fractionalBitNum = 8;
    // functions
    public:
        // special member functions
        Fixed(void);               // default constructor
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed); // copy constructor
        ~Fixed(void);              // destructor
        // operators
        Fixed &operator=(const Fixed &fixed); // copy assignment operator
        // others
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
    private:
};

std::ostream& operator<<(std::ostream& o, const Fixed& rhs);

#endif
