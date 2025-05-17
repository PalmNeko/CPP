#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
    private:
        AForm *makePresidentialPardonForm(const std::string &target) const;
        AForm *makeRobotomyRequestForm(const std::string &target) const;
        AForm *makeShrubberyCreationForm(const std::string &target) const;
    public:
        Intern();
        Intern(const Intern &other);
        virtual ~Intern();
        Intern &operator=(const Intern &rhs);

        AForm *makeForm(const std::string &form, const std::string &target) const;
};

#endif // INTERN_HPP
