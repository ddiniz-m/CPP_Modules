
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
PresidentialPardonForm::PresidentialPardonForm() : name("Presidential Pardon"), signGrade(25), execGrade(5)
{
	std::cout << GREEN << "PresidentialPardonForm Default Constructor Called" << NC << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy_a)
{
	std::cout << GREEN << "PresidentialPardonForm Copy Assignment Operator Called" << NC << std::endl;
	this->sign = copy_a.sign;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : name("Presidential Pardon"), signGrade(25), execGrade(5)
{
	std::cout << GREEN << "PresidentialPardonForm Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string	PresidentialPardonForm::getName(void) const
{
	return(this->name);
}

bool		PresidentialPardonForm::getSign(void) const
{
	return(this->sign);
}

int			PresidentialPardonForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int			PresidentialPardonForm::getExecGrade(void) const
{
	return (this->execGrade);
}

std::string		PresidentialPardonForm::getTarget(void) const
{
	return(this->target);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target), name("Presidential Pardon"), signGrade(25), execGrade(5)
{
	std::cout << GREEN << "PresidentialPardonForm Default Constructor Called" << NC << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch(std::exception & e)
	{
		throw;
	}
}

std::ostream &operator<<(std::ostream& os, PresidentialPardonForm &Pres)
{
	os << Pres.getName() << " can only be signed by personnel with grade ";
	os << Pres.getSignGrade() << " or higher\n  and it can only be executed by personnel with grade ";
	os << Pres.getExecGrade() << " or higher.\nThis document has a sign value of: " << std::boolalpha << Pres.getSign() << "\n";
	return (os);
}