#pragma once
#include <iostream>
#include <cctype>
#include <string>


class Zombie{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce( void );
	void setname(std::string name);
private:
	std::string _name;
};

Zombie*	newZombie(std::string name);
void	randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );
