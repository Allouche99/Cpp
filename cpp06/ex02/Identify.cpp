#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
    switch (std::rand() % 3)
    {
    case 0:
        std::cout << "instantiates A as Base" << std::endl;
        return (new A);

    case 1:
        std::cout << "instantiates B as Base" << std::endl;
        return (new B);
        
    default:
        std::cout << "instantiates C as Base" << std::endl;
        return (new C);
    }
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &) {}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &) {}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &) {}
	std::cout << "Unknown" << std::endl;
}