
#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Form::Form() : name("Default"), signGrade(2), execGrade(1)
{
	std::cout << GREEN << "Form Default Constructor Called" << NC << std::endl;
	this->sign = false;
}

Form& Form::operator=(const Form &copy_a)
{
	std::cout << GREEN << "Form Copy Assignment Operator Called" << NC << std::endl;
	this->sign = copy_a.sign;
	return (*this);
}

Form::Form(const Form &copy) : name(copy.name), signGrade(150), execGrade(1)
{
	std::cout << GREEN << "Form Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Form::~Form()
{
	std::cout << RED << "Form Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Form::Form(std::string name) : name(name), signGrade(2), execGrade(1)
{
	std::cout << GREEN << "Form Name Default Constructor Called" << NC << std::endl;
	this->sign = false;
}

std::string	Form::getName(void) const
{
	return(this->name);
}

bool		Form::getSign(void) const
{
	return(this->sign);
}

int			Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int			Form::getExecGrade(void) const
{
	return (this->execGrade);
}

void		Form::setSign(bool sign)
{
	this->sign = sign;
}


void		Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		setSign(true);
}

std::ostream &operator<<(std::ostream& os, Form &Form)
{
	os << Form.getName() << " can only be signed by personnel with grade ";
	os << Form.getSignGrade() << " or higher\n  and it can only be executed by personnel with grade " << Form.getExecGrade();
	os << " or higher.\nThis document has a sign value of: " << std::boolalpha << Form.getSign() << "\n";
	return (os);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return("the grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return("the grade is too low");
}

const char	*Form::FormNotSigned::what() const throw()
{
	return("form was not signed");
}

void	Form::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}