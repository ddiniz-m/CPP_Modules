
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

// ---------------------- Orthodox Canonical AForm -----------------------------
AForm::AForm() : name("Default"), signGrade(2), execGrade(1)
{
	std::cout << GREEN << "AForm Default Constructor Called" << NC << std::endl;
	this->sign = false;
}

AForm& AForm::operator=(const AForm &copy_a)
{
	std::cout << GREEN << "AForm Copy Assignment Operator Called" << NC << std::endl;
	this->sign = copy_a.sign;
	return (*this);
}

AForm::AForm(const AForm &copy) : name(copy.name), signGrade(150), execGrade(1)
{
	std::cout << GREEN << "AForm Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

AForm::~AForm()
{
	std::cout << RED << "AForm Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical AForm -----------------------------

AForm::AForm(std::string name) : name(name), signGrade(2), execGrade(1)
{
	std::cout << GREEN << "AForm Name Default Constructor Called" << NC << std::endl;
	this->sign = false;
}

std::string	AForm::getName(void) const
{
	return(this->name);
}

bool		AForm::getSign(void) const
{
	return(this->sign);
}

int			AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int			AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

void		AForm::setSign(bool sign)
{
	this->sign = sign;
}


void		AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		setSign(true);
}

std::ostream &operator<<(std::ostream& os, AForm &AForm)
{
	os << AForm.getName() << " can only be signed by personnel with grade ";
	os << AForm.getSignGrade() << " or higher\n  and it can only be executed by personnel with grade " << AForm.getExecGrade();
	os << " or higher.\nThis document has a sign value of: " << std::boolalpha << AForm.getSign() << "\n";
	return (os);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return("the grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return("the grade is too low");
}

const char	*AForm::FormNotSigned::what() const throw()
{
	return("form was not signed");
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}