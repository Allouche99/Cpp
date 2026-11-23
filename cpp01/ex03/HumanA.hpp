#pragma once

#include <cctype>
#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
public:
	HumanA(std::string _name, Weapon &club);
	void	attack();
private:
	std::string	_name;
	Weapon		&_club;
};

