#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
    : _name("no name")
    , _grade(150)
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name)
{
    setGrade(other._grade);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat Bureaucrat::operator=(const Bureaucrat &rhs)
{
    throw std::runtime_error("Can't use operator =.");
    if (this != &rhs)
    {
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    setGrade(grade);
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw std::runtime_error("Bureaucrat::GradeTooHighException");
    else if (grade > 150)
        throw std::runtime_error("Bureaucrat::GradeTooLowException");
    _grade = grade;
}

void Bureaucrat::increment()
{
    setGrade(_grade - 1);
}

void Bureaucrat::decrement()
{
    setGrade(_grade + 1);
}
