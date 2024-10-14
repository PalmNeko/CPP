#ifndef FIXED_HPP
#define FIXED_HPP

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
        Fixed(const Fixed &fixed); // copy constructor
        ~Fixed(void);              // destructor
        // operators
        Fixed &operator=(const Fixed &fixed); // operator=
        // others
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
};

#endif
