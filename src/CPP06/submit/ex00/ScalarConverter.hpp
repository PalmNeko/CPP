#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		virtual ~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &rhs);
	public:
		static void convert(const std::string &str);
};

#endif // SCALAR_CONVERTER_HPP
