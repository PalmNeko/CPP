#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <string>

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	public:
		PresidentialPardonForm(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const std::string &name);

        virtual void execute(Bureaucrat const & executor) const;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
