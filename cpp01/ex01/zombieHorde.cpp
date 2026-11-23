#include "Zombie.hpp"

Zombie* newZombie (std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}


Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombie = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombie[i].setname(name);
		zombie[i].announce();
	}
	return zombie;
}
