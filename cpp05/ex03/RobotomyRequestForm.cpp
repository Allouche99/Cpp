#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &o)
    : AForm(o), _target(o._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        _target = o._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const
{
    std::cout << "~ta9rba9ata9~" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << _target << " failed!" << std::endl;
}