#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Identify.hpp"

int main()
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 6; i++)
	{
		Base *p = generate();
		std::cout << "  identify(ptr) : ";
		identify(p);
		std::cout << "  identify(ref) : ";
		identify(*p);
		delete p;
	}
	return 0;
}