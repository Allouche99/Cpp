
#pragma once

#include <iostream>
#include <cctype>
#include <string>

class Harl
{
public:
	Harl(void);
	void complain( std::string level );

private:
	void (Harl::*_function)(void) const;
	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;
};
