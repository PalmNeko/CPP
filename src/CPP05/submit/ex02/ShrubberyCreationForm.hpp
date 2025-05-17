#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	public:
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &name);

        virtual void execute(Bureaucrat const & executor) const;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
