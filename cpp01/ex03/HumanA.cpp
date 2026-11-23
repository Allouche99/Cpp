#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club) :
				_name(name), _club(club)
{}

void HumanA::attack(void)
{
	std::cout << this->_name << " attack whith their "
			  << this->_club.getType()
			  << std::endl;
}
