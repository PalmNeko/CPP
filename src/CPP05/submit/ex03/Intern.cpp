#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &)
{
    // copy constructor
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs)
{
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) const
{
	const int Num = 3;
    AForm *(Intern::*makeMethods[Num])(const std::string &target) const
        = { &Intern::makePresidentialPardonForm,
            &Intern::makeRobotomyRequestForm,
            &Intern::makeShrubberyCreationForm,
          };
	std::string names[Num] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation",
	};
	for (int i = 0; i < Num; i++)
	{
		if (names[i] == form)
			return (this->*makeMethods[i])(target);
	}
    std::cout << form << " does not exist." << std::endl;
	return NULL;
}
