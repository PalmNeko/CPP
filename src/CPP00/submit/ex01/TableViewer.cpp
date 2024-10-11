#include <iostream>
#include <iomanip>
#include <string>

#include "TableViewer.hpp"

std::string ellipsis(std::string str, size_t length)
{
    if (str.size() > length)
    {
        str.resize(length - 1);
        str.append(".");
    }
    return (str);
}

void TableViewer::putHeader(std::string data1, std::string data2, std::string data3, std::string data4)
{
    std::cout << "+----------+----------+----------+----------+" << std::endl;
    TableViewer::putRow(data1, data2, data3, data4);
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void TableViewer::putRow(std::string data1, std::string data2, std::string data3, std::string data4)
{
    std::cout << "|" << std::setw(10) << ellipsis(data1, 10);
    std::cout << "|" << std::setw(10) << ellipsis(data2, 10);
    std::cout << "|" << std::setw(10) << ellipsis(data3, 10);
    std::cout << "|" << std::setw(10) << ellipsis(data4, 10) << "|" << std::endl;
}

void TableViewer::putFooter(void)
{
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}
