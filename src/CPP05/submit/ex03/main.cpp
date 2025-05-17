#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ALIGN_WIDTH 35
#define LEFT_ALIGN std::left << std::setw(ALIGN_WIDTH)

void testForm();

int main(void)
{
    std::cout << std::endl;
    testForm();
    std::cout << std::endl;
    return 0;
}

void testForm()
{
    Bureaucrat *targets[7];
    targets[0] = new Bureaucrat("Alice", 150);
    targets[1] = new Bureaucrat("Bob", 140);
    targets[2] = new Bureaucrat("Chris", 130);
    targets[3] = new Bureaucrat("David", 60);
    targets[4] = new Bureaucrat("Elon", 30);
    targets[5] = new Bureaucrat("Fern", 20);
    targets[6] = new Bureaucrat("Golem", 3);

    AForm *forms[3];
    forms[0] = new PresidentialPardonForm("President Form");
    forms[1] = new RobotomyRequestForm("Robotomy Form");
    forms[2] = new ShrubberyCreationForm("Shrubbery Form");

    for (int form_index = 0; form_index < 3; form_index++)
    {
        std::cout << "\e[34mStart: \e[m" << forms[form_index]->getName() << *forms[form_index]
                  << std::endl;
        for (int target_index = 0; target_index < 7; target_index++)
        {
            try
            {
                if (forms[form_index]->getIsSigned() == false)
                    targets[target_index]->signForm(*forms[form_index]);
                bool result;
                result = targets[target_index]->executeForm(*forms[form_index]);
                if (result)
                {
                    std::cout << "\e[32mDone: \e[m" << forms[form_index]->getName()
                              << std::endl;
                    break;
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "\e[31mError:\e[m " << targets[target_index]->getName() << ": "
                          << e.what() << std::endl;
            }
        }
    }

    for (int i = 0; i < 7; i++)
        delete targets[i];
    for (int i = 0; i < 3; i++)
        delete forms[i];
}
