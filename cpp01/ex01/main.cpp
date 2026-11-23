#include "Zombie.hpp"

int main()
{
	Zombie* zombie;

	zombie = zombieHorde(5, "jud");
	delete [] zombie;

	return 0;
}
