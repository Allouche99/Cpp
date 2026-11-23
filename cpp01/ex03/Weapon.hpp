#pragma once

#include <iostream>
#include <cctype>
#include <string>

class Weapon {
public:
	Weapon(std::string weapon);
	const std::string&	getType() const;
	void				setType(std::string type);
private:
	std::string _type;
};
