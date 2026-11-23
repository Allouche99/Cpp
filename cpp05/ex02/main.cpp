#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat noob("Noob", 150);
		ShrubberyCreationForm s("home");
		RobotomyRequestForm r("Bender");
		PresidentialPardonForm p("Arthur");

		noob.executeForm(s);   
		noob.signForm(s);
		boss.signForm(s);
		boss.signForm(r);
		boss.signForm(p);
		noob.executeForm(s);   
		boss.executeForm(s);
		boss.executeForm(r);
		boss.executeForm(r);   
		boss.executeForm(p);
	}
	catch (std::exception &e) { std::cout << e.what() << std::endl; }
	return 0;
}