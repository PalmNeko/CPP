#include "BitcoinExchange.hpp"

#include <cmath>

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <limits>

typedef std::map<BitcoinExchange::Date, double> BitcoinMap;

int _main(int argc, char *argv[]);
BitcoinMap createBitcoinMap(std::ifstream &dataFile);
void printExchangeRate(const BitcoinMap &coinMap, std::ifstream &inputFile);
void printHaveExchangeRate(const BitcoinMap &coinMap, const BitcoinExchange &exchange);

int main(int argc, char *argv[])
{
    try
    {
        _main(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}

int _main(int argc, char *argv[])
{
    if (argc != 2)
        throw std::runtime_error("arg[1]: could not open file.");

    std::ifstream data;
    data.open("data.csv");
    if (!data.good())
        throw std::runtime_error("data.csv: could not open file.");

    BitcoinMap rateTable = createBitcoinMap(data);
    data.close();

    std::ifstream input_file;
    input_file.open(argv[1]);
    if (!input_file.good())
        throw std::runtime_error(std::string(argv[1]) + ": could not open file.");

    printExchangeRate(rateTable, input_file);
    return 0;
}

BitcoinMap createBitcoinMap(std::ifstream &dataFile)
{
    std::string line;
    bool hasHeader;
    BitcoinMap map;

    long lineNo = 0;
    hasHeader = false;
    while (std::getline(dataFile, line))
    {
        ++lineNo;
        if (line.empty())
            continue;
        std::string linoStr = BitcoinExchange::Utils::to_string<long>(lineNo);
        std::map<size_t, std::string> fields = BitcoinExchange::Utils::split(line, ",");

        if (fields.size() != 2 || fields[0].empty() || fields[1].empty())
            throw std::runtime_error("Bad data format: line:" + linoStr);

        std::string &dateStr = fields[0];
        std::string &valueStr = fields[1];

        if (dateStr == "date" && valueStr == "exchange_rate")
            continue;

        BitcoinExchange::Date date;
        double value;
        try
        {
            date = BitcoinExchange::Date::toDate(dateStr);
            value = BitcoinExchange::Utils::toDouble(valueStr);
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error("Bad data format: line:" + linoStr + " :" + e.what());
        }
        map.insert(std::pair<BitcoinExchange::Date, double>(date, value));
    }
    if (map.size() == 0)
        throw std::runtime_error("No input line");
    return map;
}

void proccessExchangeRate(const BitcoinMap &coinMap, const std::string &line);

void printExchangeRate(const BitcoinMap &coinMap, std::ifstream &inputFile)
{
    std::string line;

    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;
        try
        {
            proccessExchangeRate(coinMap, line);
        }
        catch (const std::exception &e)
        {
			std::cerr << "Error: " << e.what() << std::endl;
		}
    }
}

void proccessExchangeRate(const BitcoinMap &coinMap, const std::string &line)
{
    std::map<size_t, std::string> fields = BitcoinExchange::Utils::split(line, "|");

    if (fields.size() != 2 || fields[0].empty() || fields[1].empty())
        throw std::runtime_error("bad input => " + line);

    std::string &dateStr = fields[0];
    std::string &valueStr = fields[1];

    if (dateStr == "date" && valueStr == "value")
        return;

    BitcoinExchange::Date date;
    double value;
    date = BitcoinExchange::Date::toDate(dateStr);
    value = BitcoinExchange::Utils::toDouble(valueStr);
    BitcoinExchange exchange(date, value);
    printHaveExchangeRate(coinMap, exchange);
}

void printHaveExchangeRate(const BitcoinMap &coinMap, const BitcoinExchange &exchange)
{
    BitcoinMap::const_iterator nowRate;

    if (coinMap.size() == 0 || exchange.getDate() < coinMap.begin()->first)
        throw std::runtime_error("exchange rate is not exists");
    nowRate = coinMap.upper_bound(exchange.getDate());
    nowRate--;
		
    double nowValue;
    nowValue = nowRate->second * exchange.getValue();
    if (std::isfinite(nowValue))
        std::cout << exchange.getDate() << " => " << exchange.getValue() << " = " << nowValue
                  << std::endl;
    else
        throw std::runtime_error("calculate rate is too large number");
    return;
}
