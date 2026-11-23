#include "Fixed.hpp"
#include <climits>
#include <cmath>

int const Fixed::_nbBits = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const nb) : _value(0)
{
	// std::cout << "Int constructor called" << std::endl;
	if (nb > (INT_MAX >> Fixed::_nbBits))
		this->_value = INT_MAX;
	else if (nb < (INT_MIN >> Fixed::_nbBits))
		this->_value = INT_MIN;
	else
		this->_value = nb << Fixed::_nbBits;
}

Fixed::Fixed(float const nb) : _value(0)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(nb * (1 << Fixed::_nbBits)));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << Fixed::_nbBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_nbBits);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

bool Fixed::operator<(Fixed const & other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator<=(Fixed const & other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator>(Fixed const & other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator>=(Fixed const & other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator==(Fixed const & other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(Fixed const & other) const
{
	return !(this->_value == other._value);
}

Fixed Fixed::operator+(Fixed const & other) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return (result);
}

Fixed Fixed::operator-(Fixed const & other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return (result);
}

Fixed Fixed::operator*(Fixed const & other) const
{
	Fixed result;
	result.setRawBits((this->_value * other._value) >> Fixed::_nbBits);
	return (result);
}

Fixed Fixed::operator/(Fixed const & other) const
{
	Fixed result;
	result.setRawBits((this->_value << Fixed::_nbBits) / other._value);
	return (result);
}

Fixed & Fixed::operator++(void)
{
	this->_value = this->_value + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value = this->_value + 1;
	return (temp);
}

Fixed & Fixed::operator--(void)
{
	this->_value = this->_value - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value = this->_value - 1;
	return (temp);
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}