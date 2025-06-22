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
		static double rpn(const std::string &str);
		static double plus(const double x, const double y);
		static double minus(const double x, const double y);
		static double multiplies(const double x, const double y);
		static double divides(const double x, const double y);
};

#endif // RPN_HPP
