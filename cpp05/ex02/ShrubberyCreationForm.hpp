#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
    virtual void action() const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &o);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &o);
    virtual ~ShrubberyCreationForm();
};

#endif