#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN
{
private:
    std::string     _expression;
    std::stack<int> _stack;

    bool isOperator(const std::string &token) const;
    void executeOperation(char op);

public:
    RPN();
    RPN(const std::string &expression);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    void calculate();
};

#endif