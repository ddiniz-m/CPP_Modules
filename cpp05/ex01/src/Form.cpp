
#include "../inc/Form.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Form::Form() : name("Default"), signGrade(150), execGrade(1)
{
	std::cout << GREEN << "Form Default Constructor Called" << NC << std::endl;
	this->sign = 0;
}

Form& Form::operator=(const Form &copy_a)
{
	std::cout << GREEN << "Form Copy Assignment Operator Called" << NC << std::endl;
	this->sign = copy_a.sign;
	return (*this);
}

Form::Form(const Form &copy) : name("Default"), signGrade(150), execGrade(1)
{
	std::cout << GREEN << "Form Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Form::~Form()
{
	std::cout << RED << "Form Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

const std::string	Form::getName(void) const
{
	return(this->name);
}

bool				Form::getSign(void) const
{
	return(this->sign);
}

const int			Form::getSignGrade(void) const
{
	return (this->signGrade);
}

const int			Form::getExecGrade(void) const
{
	return (this->execGrade);
}

void			Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	Bureaucrat.myExeception(Bureaucrat.getGrade());
	Bureaucrat.signForm(this->getSign(), this->getName());
}

std::ostream &operator<<(std::ostream& os, Form &form)
{
	if (form.getSign())
		os << "Form " << form.getName() << "" << " is signed";
	else
		os << "Form " << form.getName() << "" << " is NOT signed";
	return (os);
}