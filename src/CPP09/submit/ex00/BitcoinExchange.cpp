#include "BitcoinExchange.hpp"
#include <algorithm>
#include <functional>
#include <sstream>
#include <map>
#include <iomanip>

#pragma region BitcoinExchange

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
    if (this != &rhs)
    {
        this->_date = rhs._date;
        this->_value = rhs._value;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(const Date &date, double value)
    : _date(date)
    , _value(value)
{
    BitcoinExchange::validateValue(value);
}

bool BitcoinExchange::lessThanWithDate(const BitcoinExchange &rhs) const
{
    return (_date < rhs._date);
}

const BitcoinExchange::Date &BitcoinExchange::getDate() const
{
    return _date;
}

double BitcoinExchange::getValue() const
{
    return _value;
}

void BitcoinExchange::validateValue(double value)
{
    if (value > 1000)
        throw std::runtime_error("too large a number.");
    else if (value < 0)
        throw std::runtime_error("not a positive number.");
}

#pragma endregion

//// Utils /////

#pragma region Utils 

std::string BitcoinExchange::Utils::trim(const std::string &str)
{
    std::string whitespaces(" \t\f\v\n\r");
    size_t left;
    size_t right;

    left = str.find_first_not_of(whitespaces);
    if (left == std::string::npos)
        left = 0;

    right = str.find_last_not_of(whitespaces) + 1;
    if (right == std::string::npos)
        right = 0;
    return str.substr(left, right - left);
}

int BitcoinExchange::Utils::toInt(const std::string &str)
{
    if (str.find_first_not_of("0123456789") != std::string::npos)
        throw std::runtime_error("Not a integer.");
    std::istringstream iss(str);

    int value;
    iss >> value;
    if (iss.fail())
        throw std::runtime_error("Not invalid value");
    return value;
}

double BitcoinExchange::Utils::toDouble(const std::string &str)
{
    std::istringstream iss(str);

    double value;
    iss >> value;
    if (iss.fail())
        throw std::runtime_error("Not invalid value");
    else if (iss.peek() != -1 && iss.peek() != '\n')
        throw std::runtime_error("Not a fraction");
    return value;
}

std::map<size_t, std::string> BitcoinExchange::Utils::split(const std::string& str, const std::string &set)
{
    size_t offset;
    size_t len;
    size_t delim_pos;
    std::map<size_t, std::string> strList;

    offset = 0;
    size_t index = 0;
    while (offset < str.size())
    {
        delim_pos = str.find_first_of(set, offset);
        if (delim_pos == std::string::npos)
            break ;
        len = delim_pos - offset;
        strList.insert(std::pair<size_t, std::string>(index, trim(str.substr(offset, len))));
        offset += len + 1;
        index++;
    }
    strList.insert(std::pair<size_t, std::string>(index, trim(str.substr(offset))));

    return strList;
}

#pragma endregion

//// Date /////
#pragma region Date

BitcoinExchange::Date::Date()
    : _year(0)
    , _month(1)
    , _day(1)
{}

BitcoinExchange::Date::Date(int year, int month, int day)
    : _year(year)
    , _month(month)
    , _day(day)
{
    validateDate(year, month, day);
}

BitcoinExchange::Date::Date(const Date &date)
{
    *this = date;
}

BitcoinExchange::Date::~Date() {}

BitcoinExchange::Date &BitcoinExchange::Date::operator=(const Date &date)
{
    if (this != &date)
    {
        this->_year = date._year;
        this->_month = date._month;
        this->_day = date._day;
    }
    return *this;
}

void BitcoinExchange::Date::validateDate(int year, int month, int day)
{
    validateYear(year);
    validateMonth(month);
    validateDay(year, month, day);
}

void BitcoinExchange::Date::validateYear(int year)
{
    if (year < 0)
        throw std::runtime_error("bad year");
}

void BitcoinExchange::Date::validateMonth(int month)
{
    if (month < 1 || month > 12)
        throw std::runtime_error("bad month");
}

void BitcoinExchange::Date::validateDay(int year, int month, int day)
{
    if (day < 1 || day > 31)
        throw std::runtime_error("bad day");

    // うるう年
    bool isLeapYear = year % 4 == 0;
    if (year % 100 == 0 && year % 400 != 0)
        isLeapYear = false;

    if (isLeapYear == false && month == 2 && day > 28)
        throw std::runtime_error(
            "bad day (non leap)");
    if (isLeapYear == true && month == 2 && day > 29)
        throw std::runtime_error("bad day (leap)");

    // 30 日までしかない月
    bool isDays30month = month == 2 || month == 4 || month == 6 || month == 9 || month == 11;
    if (isDays30month && day > 30)
        throw std::runtime_error(
            "bad day");

    // 31 日までしかない
    bool isDays31month
        = month == 1 || month == 3 || month == 5 || month == 7 || month == 10 || month == 12;
    if (isDays31month && day > 31)
        throw std::runtime_error(
            "bad day");
}

// year-month-day
BitcoinExchange::Date BitcoinExchange::Date::toDate(const std::string &str)
{
    std::map<size_t, std::string> fields = BitcoinExchange::Utils::split(str, "-");
    if (fields.size() != 3)
        throw std::runtime_error("wrong format: " + str );

    std::string &yearStr = fields[0];
    std::string &monthStr = fields[1];
    std::string &dayStr = fields[2];

    std::string numbers = "0123456789";
    if (yearStr.find_first_not_of(numbers) != std::string::npos
        || monthStr.find_first_not_of(numbers) != std::string::npos
        || dayStr.find_first_not_of(numbers) != std::string::npos)
    {
        throw std::runtime_error("wrong format: " + str);
    }

    int year = BitcoinExchange::Utils::toInt(yearStr);
    int month = BitcoinExchange::Utils::toInt(monthStr);
    int day = BitcoinExchange::Utils::toInt(dayStr);

    return BitcoinExchange::Date(year, month, day);
}

bool BitcoinExchange::Date::operator<(const BitcoinExchange::Date &date) const
{
    if (this->_year != date._year)
        return (_year < date._year);

    if (this->_month != date._month)
        return (this->_month < date._month);

    return (this->_day < date._day);
}

bool BitcoinExchange::Date::operator==(const Date &date) const
{
    return (_year == date._year && _month == date._month && _day == date._day);
}

std::string BitcoinExchange::Date::toString() const
{
    std::ostringstream oss;

    oss << _year << "-";
    oss << std::setfill('0') << std::setw(2) << _month << "-";
    oss << std::setfill('0') << std::setw(2) << _day;
    return oss.str();
}

std::ostream& operator<<(std::ostream& o, const BitcoinExchange::Date& rhs)
{
    return o << rhs.toString();
}

#pragma endregion
