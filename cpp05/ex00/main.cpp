#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try 
	{
		Bureaucrat a("Aya", 0); 
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{ 
		std::cout << e.what() << std::endl; 
	}

	try 
	{
		Bureaucrat b("Walter", 151); 
	}
	catch (std::exception &e)
	
	{
		std::cout << e.what() << std::endl;
	}
	try 
	{
		Bureaucrat c("Yssr", 2);
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.incrementGrade();
	
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl; 
	}

	try 
	{
		Bureaucrat d("Ana", 149);
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
		d.decrementGrade();
	
	}
	catch (std::exception &e) 
	{ 
		std::cout << e.what() << std::endl; 
	}

	return 0;
}