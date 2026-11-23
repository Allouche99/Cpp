#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _club(NULL)
{}

void HumanB::setWeapon(Weapon *club)
{
	this->_club = club;
}


void HumanB::attack(void)
{
	if (this->_club == NULL)
	{
		std::cout << this->_name << " is Nacked";
		std::cout << std::endl;
		return;
	}
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_club->getType() << std::endl;
}
