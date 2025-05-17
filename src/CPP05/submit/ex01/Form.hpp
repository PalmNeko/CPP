#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _requireGradeToSign;
        const int _requireGradeToExecute;

		Form operator=(const Form &rhs);

    public:
        Form();
        Form(const Form &other);
        virtual ~Form();

		Form(const std::string name, int requireGradeToSign, int requireGradeToExecute);

        const std::string &getName() const;
        bool getIsSigned() const;
        const int &getRequireGradeToSign() const;
        const int &getRequireGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &o, Form &rhs);

#endif // FORM_HPP
