#include "BitcoinExchange.hpp"
#include <fstream>    // FIX: manquait (ifstream)
#include <iostream>   // FIX: manquait (cout, cerr)
#include <cctype>     // FIX: manquait (isdigit)
#include <stdexcept>  // std::runtime_error
#include <cstdlib>    // strtod, atoi

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _data(other._data)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_data = other._data;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

// fill the map with data
void	BitcoinExchange::loadData(const std::string& filename)
{
	std::ifstream datafile(filename.c_str());

	if (!datafile.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string expression;
	std::getline(datafile, expression);

	while (std::getline(datafile, expression))
	{
		if (expression.empty())
			continue;
		std::string::size_type poscoma = expression.find(',');

		if (poscoma == std::string::npos)
			throw std::runtime_error("Error: bad expression in database => " + expression);

		std::string key = expression.substr(0, poscoma);
		double value = strtod(expression.substr(poscoma + 1).c_str(), NULL);
		_data[key] = value;
	}
}

double BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
		return it->second;
	if (it == _data.begin())
		throw std::runtime_error("Error: no date equal or lower than " + date);
	--it; // cas général (et it == end() => dernier élément)
	return it->second;
}

std::string BitcoinExchange::trim(const std::string& str)
{
	std::string::size_type begin = str.find_first_not_of(" \t\n\r");
	if (begin == std::string::npos)
		return "";
	std::string::size_type end = str.find_last_not_of(" \t\n\r");
	return str.substr(begin, end - begin + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (std::string::size_type i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& str, double& value)
{
	if (str.empty())
		return false;

	char *end;
	double r = strtod(str.c_str(), &end);
	if (end == str.c_str() || *end != '\0')
		return false;
	value = r;
	return true;
}

void    BitcoinExchange::processInput(const std::string& filename) const
{
	std::ifstream inputfile(filename.c_str());

	if (!inputfile.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string expression;
	std::getline(inputfile, expression); //saute l'en-tête "date | value"
	if (expression != "date | value")
	{
    	std::cerr << "line => " << expression << std::endl;
		throw std::runtime_error("Error: the first line must be \"date | value\"");	
	}

	while (std::getline(inputfile, expression))
	{
		expression = trim(expression);
		if (expression.empty())
			continue;
		std::string::size_type pospipe = expression.find('|');
		//affiche l'erreur et passe à la ligne suivante au lieu de
		// stopper tout le programme (le sujet attend "Error: bad input => ligne")
		if (pospipe == std::string::npos)
		{
			std::cerr << "Error: bad input => " << expression << std::endl;
			continue;
		}

		std::string date     = trim(expression.substr(0, pospipe));
		std::string valueStr = trim(expression.substr(pospipe + 1));

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << expression << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << expression << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			std::cout << date << " => " << value << " = "
					  << (value * getRate(date)) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}