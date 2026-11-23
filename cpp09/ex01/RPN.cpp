
#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &expression)
	: _expression(expression)
{
}

RPN::RPN(const RPN &other)
	: _expression(other._expression), _stack(other._stack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_expression = other._expression;
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" ||
			token == "*" || token == "/");
}

void RPN::executeOperation(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error: not enough operands");

	int first = _stack.top();
	int second;

	_stack.pop();
	second = _stack.top();

	if (op == '/' && first == 0)
		throw std::runtime_error("Error: division by zero");

	_stack.pop();

	if (op == '+')
		_stack.push(second + first);
	else if (op == '-')
		_stack.push(second - first);
	else if (op == '*')
		_stack.push(second * first);
	else if (op == '/')
		_stack.push(second / first);
	else
		throw std::runtime_error("Error: invalid operator");
}

void RPN::calculate()
{
	std::stringstream ss(_expression);
	std::string token;

	while (ss >> token)
	{
		if (isOperator(token))
		{
			executeOperation(token[0]);
		}
		else if (token.size() == 1 &&
				 std::isdigit(static_cast<unsigned char>(token[0])))
		{
			_stack.push(token[0] - '0');
		}
		else
			throw std::runtime_error("Error: invalid token");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");

	std::cout << _stack.top() << std::endl;
}

