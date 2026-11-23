#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon)
{}

const std::string& Weapon::getType() const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

