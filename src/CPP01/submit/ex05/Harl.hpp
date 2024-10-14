#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        Harl(void); // default constructor
        Harl(const Harl& harl); // copy constructor
        ~Harl(void); // destructor
        // operators
        Harl& operator=(const Harl& harl); // operator=
        // others
        void complain(std::string level);
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif
