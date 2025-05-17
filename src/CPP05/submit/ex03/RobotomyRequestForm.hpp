#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	public:
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm(const std::string &name);

        virtual void execute(Bureaucrat const & executor) const;
};

#endif // ROBOTOMY_REQUEST_FORM_HPP
