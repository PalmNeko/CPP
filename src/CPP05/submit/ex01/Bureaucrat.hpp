#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        Bureaucrat operator=(const Bureaucrat &rhs);
        void setGrade(int grade);

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        virtual ~Bureaucrat();

        Bureaucrat(const std::string name, int grade = 150);
        const std::string &getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(Form &form) const;
            
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif // BUREAUCRAT_HPP
