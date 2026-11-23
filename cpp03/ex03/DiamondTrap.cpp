#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name"), FragTrap(), ScavTrap(), _name("default")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	_hitPoints = 100;    // FragTrap
	_energyPoints = 50;  // ScavTrap
	_attackDamage = 30;  // FragTrap
	std::cout << "DiamondTrap " << _name << " constructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string &target)
{
    this->ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}