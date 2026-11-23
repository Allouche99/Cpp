#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
    const Entry table[3] = {
        { "shrubbery creation",  &Intern::createShrubbery },
        { "robotomy request",    &Intern::createRobotomy  },
        { "presidential pardon", &Intern::createPardon    }
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == table[i].name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return table[i].create(target);
        }
    }
    std::cout << "Intern cannot create \"" << name << "\": unknown form" << std::endl;
    return NULL;
}