
#include "../inc/PresidentialPardonForm.hpp"
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

PresidentialPardonForm::PresidentialPardonForm(std::string target) : target(target), name("Presidential Pardon"), signGrade(25), execGrade(5)
{
	std::cout << GREEN << "PresidentialPardonForm Default Constructor Called" << NC << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	;
}