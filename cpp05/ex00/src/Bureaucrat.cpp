
#include "../inc/Bureaucrat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Bureaucrat::Bureaucrat() : name("Default")
{
	std::cout << GREEN << "Bureaucrat Default Constructor Called" << NC << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy_a)
{
	std::cout << GREEN << "Bureaucrat Copy Assignment Operator Called" << NC << std::endl;
	this->grade = copy_a.grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	std::cout << GREEN << "Bureaucrat Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Bureaucrat::Bureaucrat(int grade, const std::string name) : name(name)
{
	std::cout << GREEN << "Bureaucrat Grade Constructor Called" << NC << std::endl;
	myExeception(grade);
	this->grade = grade;
	std::cout << "Valid grade" << "\n";
}

int	Bureaucrat::myExeception(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	return (0);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Out of range. Grade too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Out of range. Grade too low");
}

int			Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

void	Bureaucrat::Increment(void)
{
	int	gradeBuf;

	gradeBuf = this->grade - 1;
	if (myExeception(gradeBuf))
		return ;
	this->grade--;
}

void	Bureaucrat::Decrement(void)
{
	int	gradeBuf;

	gradeBuf = this->grade + 1;
	if (myExeception(gradeBuf))
		return ;
	this->grade++;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat)
{
	os << "Bureaucrat Mr." << bureaucrat.getName() << " has grade " << bureaucrat.getGrade() << "\n";
	return (os);
}
