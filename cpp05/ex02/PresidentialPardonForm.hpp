#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    virtual void action() const;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &o);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &o);
    virtual ~PresidentialPardonForm();
};

#endif