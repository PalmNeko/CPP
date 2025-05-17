#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("no_name", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other)
{
    // copy constructor
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
    : AForm(name, 72, 45)
{}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    validateCanExecute(executor);
    std::cout << "Whee......." << std::endl;
    std::cout << "Ahhh!!!!!!! (" << executor.getName() << ")" << std::endl;
    srand(time(NULL));
    if (rand() % 2 == 0)
        std::cout << "Success: Robotomy Operation!!!" << std::endl;
    else
        std::cout << "Failure: Robotomy Operation..." << std::endl;
    return;
}
