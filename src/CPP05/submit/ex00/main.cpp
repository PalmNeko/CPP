#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>

#define ALIGN_WIDTH 15

void testBureaucrat();

int main(void)
{
    std::cout << std::endl;
    try
    {
        testBureaucrat();
    }
    catch (const std::exception &e)
    {
        std::cout << std::setw(ALIGN_WIDTH) << "Error: " << e.what() << std::endl;
        return 1;
    }
    std::cout << std::endl;
    return 0;
}

void testBureaucrat()
{
    std::cout << " === Successful Constructor === " << std::endl;
    {
        Bureaucrat lowestGrader("lowestGrader", 150);
        Bureaucrat highestGrader("highestGrader", 1);

        std::cout << std::setw(ALIGN_WIDTH) << " low grade: " << lowestGrader << std::endl;
        std::cout << std::setw(ALIGN_WIDTH) << " high grade: " << highestGrader << std::endl;
    }

    std::cout << " === Successful Copy Constructor === " << std::endl;
    {
        Bureaucrat src("src", 150);

        std::cout << std::setw(ALIGN_WIDTH) << " src: " << src << std::endl;
        Bureaucrat dst(src);
        std::cout << std::setw(ALIGN_WIDTH) << " dst: " << dst << std::endl;
    }

    std::cout << " === Successful increment & decrement === " << std::endl;
    {
        Bureaucrat grading("grading", 150);
        std::cout << std::setw(ALIGN_WIDTH) << " before: " << grading << std::endl;
        grading.increment();
        std::cout << std::setw(ALIGN_WIDTH) << " increment: " << grading << std::endl;
        grading.decrement();
        std::cout << std::setw(ALIGN_WIDTH) << " & decrement: " << grading << std::endl;
    }

    std::cout << " === Constructor Exception  - Bureaucrat::GradeTooLowException === "
              << std::endl;
    {
        try
        {
            Bureaucrat overLowestGrader("overLowestGrader", 151);
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cout << std::setw(ALIGN_WIDTH) << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << " === Constructor Exception  - Bureaucrat::GradeTooHighException === "
              << std::endl;
    {
        try
        {
            Bureaucrat overHighestGrader("overHighestGrader", 0);
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cout << std::setw(ALIGN_WIDTH) << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << " === Increment Exception === " << std::endl;
    {
        try
        {
            Bureaucrat highestGrader("highestGrader", 1);
            std::cout << std::setw(ALIGN_WIDTH) << " now: " << highestGrader << std::endl;
            std::cout << std::setw(ALIGN_WIDTH) << " INFO: " << "I will do increment()."
                      << std::endl;
            highestGrader.increment();
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cout << std::setw(ALIGN_WIDTH) << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << " === Decrement Exception === " << std::endl;
    {
        try
        {
            Bureaucrat lowestGrader("lowestGrader", 150);
            std::cout << std::setw(ALIGN_WIDTH) << " now: " << lowestGrader << std::endl;
            std::cout << std::setw(ALIGN_WIDTH) << " INFO: " << "I will do decrement()."
                      << std::endl;
            lowestGrader.decrement();
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cout << std::setw(ALIGN_WIDTH) << "Error: " << e.what() << std::endl;
        }
    }
}
