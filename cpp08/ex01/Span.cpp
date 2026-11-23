#include "Span.hpp"

#include <algorithm>
#include <iterator>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int n) : _N(n)
{
}

Span::Span(const Span &other)
	: _N(other._N), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::out_of_range("The span is full");

	_numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements");
	std::sort(_numbers.begin(), _numbers.end());

	long long minSpan = std::numeric_limits<long long>::max();
	std::vector<int>::iterator it = _numbers.begin();
	std::vector<int>::iterator next = it + 1;

	while (next != _numbers.end())
	{
		long long diff = static_cast<long long>(*next) - *it;
		if (diff < minSpan)
			minSpan = diff;
		++it;
		++next;
	}
	if (minSpan > std::numeric_limits<int>::max())
		throw std::overflow_error("Span exceeds int range");
	return static_cast<int>(minSpan);
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements");

	std::sort(_numbers.begin(), _numbers.end());

	long long span = static_cast<long long>(_numbers.back())
				   - static_cast<long long>(_numbers.front());

	if (span > std::numeric_limits<int>::max())
		throw std::overflow_error("Span exceeds int range");

	return static_cast<int>(span);
}

void Span::addNumbers(std::vector<int>::const_iterator begin,
					  std::vector<int>::const_iterator end)
{
	std::size_t count = static_cast<std::size_t>(
		std::distance(begin, end));

	if (count > _N - _numbers.size())
		throw std::out_of_range("The span is full");

	_numbers.insert(_numbers.end(), begin, end);
}