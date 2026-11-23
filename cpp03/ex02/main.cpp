#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- constroctors demo ---" << std::endl;
	FragTrap	aya("aya");
	FragTrap	ana;
	FragTrap	yas("anayas");
	ana = yas;

	ana.highFivesGuys();
	std::cout << "--- energy exhaustion ---" << std::endl;
	for(int i = 0; i <=100; i++)
		aya.attack("anayas");
	
	std::cout << "--- destruction chain ---" << std::endl;
	return 0;
}