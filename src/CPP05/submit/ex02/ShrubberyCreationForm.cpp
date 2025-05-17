#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("no_name", 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other)
{
    // copy constructor
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        // assignment logic
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
    : AForm(name, 145, 137)
{}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    validateCanExecute(executor);

    std::ofstream asciiStream;
    std::string filename = getName() + std::string("_shrubbery");

    asciiStream.open(filename.c_str());
    if (!asciiStream.good())
        throw std::runtime_error("Can't open :" + filename);
    asciiStream << "   .    " << std::endl;
    asciiStream << "  *|*   " << std::endl;
    asciiStream << " * | *  " << std::endl;
    asciiStream << "* *|* * " << std::endl;
    asciiStream << "  /|\\   " << std::endl;
    asciiStream.close();
    return;
}
