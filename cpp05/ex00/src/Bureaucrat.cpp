
#include "../inc/Bureaucrat.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Bureaucrat::Bureaucrat()
{
	std::cout << GREEN << "Bureaucrat Default Constructor Called" << NC << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy_a)
{
	std::cout << GREEN << "Bureaucrat Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << GREEN << "Bureaucrat Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

Bureaucrat::Bureaucrat(int grade)
{
	std::cout << GREEN << "Bureaucrat Grade Constructor Called" << NC << std::endl;
	myExeception(grade);
	this->grade = grade;
}

int	Bureaucrat::myExeception(int grade)
{
	try
	{
		if (grade >= 1 && grade <= 150)
			std::cout << "Valid grade" << "\n";
		else if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}

std::exception		&Bureaucrat::GradeTooHighException(void)
{
	throw std::out_of_range("Out of range. Grade too high.");
}

std::exception		&Bureaucrat::GradeTooLowException(void)
{
	throw std::out_of_range("Out of range. Grade too low");
}

int			Bureaucrat::getGrade(void)
{
	return (this->grade);
}

std::string	Bureaucrat::getName(void)
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

void	Bureaucrat::setName(std::string name)
{
	this->name = name;
}