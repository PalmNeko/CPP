#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <stdexcept>
#include <string>
#include <map>

class BitcoinExchange
{
    public:
        struct Date
        {
            private:
                int _year;
                int _month;
                int _day;

            public:
                static void validateDateFormat(const std::string &date);
                static void validateDate(int year, int month, int day);
                static void validateYear(int year);
                static void validateMonth(int month);
                static void validateDay(int year, int month, int day);

                static Date toDate(const std::string &str);

                Date();
                Date(int year, int month, int day);
                Date(const Date &date);
                virtual ~Date();
                Date &operator=(const Date &date);

                bool operator<(const Date &date) const;
                bool operator==(const Date &date) const;
                

                std::string toString() const;
        };

        struct Utils
        {
                static std::string trim(const std::string &str);

                template <typename T> static std::string to_string(const T &val);
                static int toInt(const std::string &str);
                static double toDouble(const std::string &str);
                // skip spaces
                static std::map<size_t, std::string> split(const std::string& str, const std::string &set = ",");
        };

    private:
        BitcoinExchange::Date _date;
        double _value;

    private:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        
        static void validateValue(double value);
        
    public:
        virtual ~BitcoinExchange();
        BitcoinExchange(const Date &date, double value);

        bool lessThanWithDate(const BitcoinExchange &rhs) const;
        const Date &getDate() const;
        double getValue() const;
};

std::ostream& operator<<(std::ostream& o, const BitcoinExchange::Date& rhs);

/** templates */
#include <sstream>
template <typename T> std::string BitcoinExchange::Utils::to_string(const T &val)
{
    std::ostringstream oss;

    oss << val;
    return oss.str();
}

#endif // BITCOIN_EXCHANGE_HPP
