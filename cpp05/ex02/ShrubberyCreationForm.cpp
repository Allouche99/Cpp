#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &o)
    : AForm(o), _target(o._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::action() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
    {
        std::cout << "Cannot create shrubbery file" << std::endl;
        return;
    }
    file << "    *\n"
            "   ***\n"
            "  *****\n"
            " *******\n"
            "*********\n"
            "    |\n";
}