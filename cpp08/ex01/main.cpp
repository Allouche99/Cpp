#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	try
	{
		Span sp(7);

		std::vector<int> numbers;
		numbers.push_back(6);
		numbers.push_back(3);
		numbers.push_back(17);
		numbers.push_back(9);
		numbers.push_back(11);

		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		sp.addNumber(42);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Span sp(2);
	
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
	
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}