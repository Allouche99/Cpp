#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap 
{
public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
	DiamondTrap &operator=(const DiamondTrap &other);
    DiamondTrap(const DiamondTrap &other);
	~DiamondTrap();

	void attack(const std::string &target);
	void whoAmI(void);
private:
    std::string _name;
};
#endif
