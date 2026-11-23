#include "Zombie.hpp"

int main()
{
	Zombie* zombie1;

	Zombie	zombie2("neil");

	zombie2.announce();
	zombie1 = newZombie("yassir");
	zombie1->announce();
	randomChump("jud");

	delete  zombie1;
	return 0;
}
