#pragma once

#include <cctype>
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB{
public:
	HumanB(std::string name);
	void	attack();
	void	setWeapon(Weapon *club);
private:
	std::string	_name;
	Weapon		*_club;
};

