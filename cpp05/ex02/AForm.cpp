#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    if (gradeToSign < 1 || gradeToExec < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &o)
    : _name(o._name), _signed(o._signed),
      _gradeToSign(o._gradeToSign), _gradeToExec(o._gradeToExec) {}

AForm &AForm::operator=(const AForm &o)
{
    if (this != &o)
        _signed = o._signed;
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExec)
        throw GradeTooLowException();
    action();
}

const char *AForm::GradeTooHighException::what() const throw() { return "Form grade too high!"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Form grade too low!"; }
const char *AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << f.getName() << ", signed: " << (f.isSigned() ? "yes" : "no")
       << ", sign grade: " << f.getGradeToSign()
       << ", exec grade: " << f.getGradeToExec();
    return os;
}