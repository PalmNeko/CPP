#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
	private:
		RPN();
		RPN(const RPN &other);
		virtual ~RPN();
		RPN &operator=(const RPN &rhs);
	public:
		static int rpn(const std::string &str);
		static int plus(const int x, const int y);
		static int minus(const int x, const int y);
		static int multiplies(const int x, const int y);
		static int divides(const int x, const int y);
};

#endif // RPN_HPP
