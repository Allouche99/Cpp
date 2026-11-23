#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}


void Zombie::announce(void)
{
	std::cout << this->_name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}

void	Zombie::setname(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std :: cout << this->_name << " destroyed" << std::endl;
}
