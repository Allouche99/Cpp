#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};

enum Type { T_CHAR, T_INT, T_FLOAT, T_DOUBLE, T_INVALID };

#endif