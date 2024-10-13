#include "Replace.hpp"
#include <string>
#include <iostream>

void testReplace_replace_string(
    const std::string& src,
    const std::string& find,
    const std::string& replace,
    const std::string& toBe);

int main(void)
{
    try{
        std::cout << "test std::string Replace::replace(const std::string& src, const std::string& find, const std::string& replace)" << std::endl;
        testReplace_replace_string("", "abc", "ABC", ""); // null src
        testReplace_replace_string("abc", "abc", "ABC", "ABC"); // full same
        testReplace_replace_string("abc  ", "abc", "ABC", "ABC  "); // head same
        testReplace_replace_string("  abc", "abc", "ABC", "  ABC"); // tail same
        testReplace_replace_string("aaa", "a", "AA", "AAAAAA"); // multi same
        testReplace_replace_string("I'm lucky boy. ", "boy", "girl", "I'm lucky girl. "); // basic use
        testReplace_replace_string("I'm lucky boy. ", "boy", "", "I'm lucky . "); // delete found string
        testReplace_replace_string("I'm lucky boy. ", "", "girl", "I'm lucky boy. "); // find string is null
        testReplace_replace_string("I'm lucky boy. ", "I'm lucky boy. ", "girl", "girl"); // full replace
        testReplace_replace_string("I'm lucky boy. ", "I'm lucky boy. ", "", ""); // full delete
        std::cout << std::endl;
    }
    catch (int testNo) {
        std::cout << "error test no: " << testNo << std::endl;
        return (1);
    }
    std::cout << "done!" << std::endl;
    return (0);
}


void testReplace_replace_string(
    const std::string& src,
    const std::string& find,
    const std::string& replace,
    const std::string& toBe)
{
    static int testNo;
    std::cout << "[" << testNo << "]";
    std::string result = Replace::replace(src, find, replace);
    if (result != toBe)
    {
        std::cerr << "Error: replacement: " << testNo << std::endl;
        std::cerr << "\texpect: " << toBe << std::endl;
        std::cerr << "\tresult: " << result << std::endl;
        std::cerr << "\tsrc: " << src << std::endl;
        std::cerr << "\tfind: " << src << std::endl;
        std::cerr << "\treplace: " << src << std::endl;
        throw testNo;
    }
    testNo++;
    return ;
}
