#ifndef TABLE_VIEWER_HPP
# define TABLE_VIEWER_HPP

# include <string>

class TableViewer
{
    public:
        static void putHeader(std::string data1, std::string data2, std::string data3, std::string data4);
        static void putRow(std::string data1, std::string data2, std::string data3, std::string data4);
        static void putFooter(void);
};

#endif
