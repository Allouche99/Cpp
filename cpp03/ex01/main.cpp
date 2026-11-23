#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
		ScavTrap s("aya");

		s.attack("ana");
		s.takeDamage(30);
		s.beRepaired(10);
		s.guardGate();

		ScavTrap other;
		other = s;

		std::cout << "--- energy exhaustion ---" << std::endl;
		for (int i = 0; i < 50; i++)
			s.attack("yas");
		s.attack("yas");
		std::cout << "--- destruction chain ---" << std::endl;
	return 0;
}