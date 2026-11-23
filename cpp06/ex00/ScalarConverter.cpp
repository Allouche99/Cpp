#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cfloat>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }
ScalarConverter::~ScalarConverter() {}



bool isPseudoFloat(const std::string &s)
{
	return s == "nanf" || s == "+inff" || s == "-inff";
}
bool isPseudoDouble(const std::string &s)
{
	return s == "nan" || s == "+inf" || s == "-inf";
}
bool isInt(const std::string &s)
{
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.size())
		return false;
	for (; i < s.size(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}
// [sign] digits '.' digits   (at least one digit, exactly one dot)
bool isDecimal(const std::string &s)
{
	size_t i = 0, digits = 0, dots = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.size(); i++)
	{
		if (s[i] == '.')
			dots++;
		else if (std::isdigit(static_cast<unsigned char>(s[i])))
			digits++;
		else
			return false;
	}
	return dots == 1 && digits > 0;
}
bool isFloat(const std::string &s)
{
	return s.size() > 1 && s[s.size() - 1] == 'f'
		&& isDecimal(s.substr(0, s.size() - 1));
}

Type detect_type(const std::string &s)
{
	if (s.empty())
		return T_INVALID;
	if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return T_CHAR;
	if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
		return T_CHAR;
	if (isInt(s))
		return T_INT;
	if (isPseudoFloat(s) || isFloat(s))
		return T_FLOAT;
	if (isPseudoDouble(s) || isDecimal(s))
		return T_DOUBLE;
	return T_INVALID;
}
// Number of digits after the '.' in the literal (min 1), used for display.
int decimals(const std::string &s)
{
	size_t dot = s.find('.');
	if (dot == std::string::npos)
		return 1;
	size_t end = s.size();
	if (s[end - 1] == 'f')
		end--;
	int n = static_cast<int>(end - dot - 1);
	return n < 1 ? 1 : n;
}
void printChar(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(d) << "'";
	std::cout << std::endl;
}
void printInt(double d)
{
	std::cout << "int: ";
	if (std::isnan(d) || d < static_cast<double>(INT_MIN)
		|| d > static_cast<double>(INT_MAX))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(d);
	std::cout << std::endl;
}
void printFloat(double d, int prec)
{
	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inff" : "+inff");
	else if (std::fabs(d) > static_cast<double>(FLT_MAX))
		std::cout << "impossible";
	else
		std::cout << std::fixed << std::setprecision(prec)
			<< static_cast<float>(d) << "f";
	std::cout << std::endl;
}
void printDouble(double d, int prec)
{
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "+inf");
	else
		std::cout << std::fixed << std::setprecision(prec) << d;
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	Type	type = detect_type(literal);
	double	value = 0;
	int		prec = 1;

	switch (type)
	{
	case T_CHAR:
		value = static_cast<double>(static_cast<unsigned char>(
			literal.size() == 3 ? literal[1] : literal[0]));
		break;
	case T_INT:
		value = std::strtod(literal.c_str(), NULL);
		break;
	case T_FLOAT:
		if (literal == "nanf")
			value = std::strtod("nan", NULL);
		else if (literal == "+inff")
			value = std::strtod("inf", NULL);
		else if (literal == "-inff")
			value = std::strtod("-inf", NULL);
		else
			value = static_cast<double>(static_cast<float>(
				std::strtod(literal.c_str(), NULL)));
		prec = decimals(literal);
		break;
	case T_DOUBLE:
		if (literal == "nan")
			value = std::strtod("nan", NULL);
		else if (literal == "+inf")
			value = std::strtod("inf", NULL);
		else if (literal == "-inf")
			value = std::strtod("-inf", NULL);
		else
			value = std::strtod(literal.c_str(), NULL);
		prec = decimals(literal);
		break;
	default:
		std::cout << "Invalid literal" << std::endl;
		return;
	}
	printChar(value);
	printInt(value);
	printFloat(value, prec);
	printDouble(value, prec);
}