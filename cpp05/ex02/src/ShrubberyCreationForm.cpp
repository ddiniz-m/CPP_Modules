
#include "../inc/ShrubberyCreationForm.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
ShrubberyCreationForm::ShrubberyCreationForm() : name("Shrubbery Request"), signGrade(145), execGrade(137)
{
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor Called" << NC << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy_a)
{
	std::cout << GREEN << "ShrubberyCreationForm Copy Assignment Operator Called" << NC << std::endl;
	this->sign = copy_a.sign;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : name("Shrubbery Request"), signGrade(145), execGrade(137)
{
	std::cout << GREEN << "ShrubberyCreationForm Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target), name("Shrubbery Request"), signGrade(145), execGrade(137)
{
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor Called" << NC << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	;
}