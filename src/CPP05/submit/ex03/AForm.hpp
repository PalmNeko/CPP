#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _requireGradeToSign;
        const int _requireGradeToExecute;

		AForm &operator=(const AForm &rhs);

    public:
        AForm();
        AForm(const AForm &other);
        virtual ~AForm();

		AForm(const std::string name, int requireGradeToSign, int requireGradeToExecute);

        const std::string &getName() const;
        bool getIsSigned() const;
        const int &getRequireGradeToSign() const;
        const int &getRequireGradeToExecute() const;

        void beSigned(const Bureaucrat &bureaucrat);

        bool canExecute(Bureaucrat const & executer) const;
        bool canSign(Bureaucrat const & executer) const;
        void validateCanExecute(Bureaucrat const & executer) const;

        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, AForm &rhs);

#endif // AFORM_HPP
