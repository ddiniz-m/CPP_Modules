
#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Form::Form() : name("Default"), signGrade(2), execGrade(1)
{
	this->sign = false;
	std::cout << GREEN << "Form Default Constructor Called" << NC << std::endl;
	try
	{
		checkGrade(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n";
		throw;
	}
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
	try
	{
		checkGrade(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n";
		throw;
	}
}

Form::~Form()
{
	std::cout << RED << "Form Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Form::Form(std::string name) : name(name), signGrade(200), execGrade(1)
{
	this->sign = false;
	std::cout << GREEN << "Form Name Default Constructor Called" << NC << std::endl;
	try
	{
		checkGrade(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << "\n";
		throw;
	}
}

void	Form::checkGrade(Form &form)
{
	if (form.getExecGrade() > 150 || form.getExecGrade() < 1)
	{
		std::cout << "execGrade Error: ";
		if (form.getExecGrade() > 150)
			throw GradeTooLowException();
		throw GradeTooHighException();
	}
	if (form.getSignGrade() > 150  || form.getSignGrade() < 1)
	{
		std::cout << "signGrade Error: ";
		if (form.getSignGrade() > 150)
			throw GradeTooLowException();
		throw GradeTooHighException();
	}
}

std::string	Form::getName(void) const
{
	return(this->name);
}

bool		Form::getSign(void) const
{
	return(this->sign);
}

void		Form::setSign(bool sign)
{
	this->sign = sign;
}

int			Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int			Form::getExecGrade(void) const
{
	return (this->execGrade);
}

void		Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		setSign(true);
}

std::ostream &operator<<(std::ostream& os, Form &form)
{
	os << form.getName() << " can only be signed by personnel with grade ";
	os << form.getSignGrade() << " or higher.\nIt can only be executed by personnel with grade " << form.getExecGrade();
	os << " or higher.\nThis document has a sign value of: " << std::boolalpha << form.getSign() << "\n";
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