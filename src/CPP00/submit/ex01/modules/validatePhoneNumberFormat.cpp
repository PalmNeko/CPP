
#include <string>
#include <cctype>

bool validatePhoneNumberFormat(const std::string& str)
{
	std::string::const_iterator it = str.begin();
	std::string::const_iterator end = str.end();
	while (std::isspace(*it) && it < end)
		it++;
	while (std::isdigit(*it) && it < end)
		it++;
	while (std::isspace(*it) && it < end)
		it++;
	if (it == end)
		return (true);
	else
		return (false);
}