#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    virtual void action() const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &o);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &o);
    virtual ~RobotomyRequestForm();
};

#endif