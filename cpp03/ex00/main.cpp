#include "ClapTrap.hpp"
#include <iostream>

int main()
{

	ClapTrap a("yas");
	ClapTrap b(a);
	ClapTrap c;
	c = a;

	a.attack("ana");
	a.takeDamage(4);
	a.beRepaired(3);

	for (int i = 0; i < 10; i++)
		a.attack("ana");
	a.beRepaired(1);

	b.takeDamage(100);
	b.attack("ana");
	return 0;

	return 0;
}