#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("no_name", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other)
{
    // copy constructor
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
    : AForm(name, 25, 5)
{}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    validateCanExecute(executor);
    std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return;
}
