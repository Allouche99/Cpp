#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm *f1 = intern.makeForm("robotomy request", "Bender");
    AForm *f2 = intern.makeForm("shrubbery creation", "home");
    AForm *f3 = intern.makeForm("presidential pardon", "mehdi");
    AForm *f4 = intern.makeForm("kawa", "Bob");   // NULL

    if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
	}
    if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
	}
    if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);
	}

    delete f1;
    delete f2;
    delete f3;
    delete f4;
    return 0;
}