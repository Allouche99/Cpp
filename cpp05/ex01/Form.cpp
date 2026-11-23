#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const 
{
	 return _name;
}

bool Form::isSigned() const 
{
	 return _signed;
}

int Form::getGradeToSign() const 
{
	 return _gradeToSign;
}

int Form::getGradeToExec() const 
{
	 return _gradeToExec;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() 
{
	return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() 
{
	return "Form grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << f.getName() << ", signed: " << (f.isSigned() ? "yes" : "no")
	   << ", sign grade: " << f.getGradeToSign()
	   << ", exec grade: " << f.getGradeToExec();
	return os;
}