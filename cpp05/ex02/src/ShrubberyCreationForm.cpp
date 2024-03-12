
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
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

std::string	ShrubberyCreationForm::getName(void) const
{
	return(this->name);
}

bool		ShrubberyCreationForm::getSign(void) const
{
	return(this->sign);
}

int			ShrubberyCreationForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int			ShrubberyCreationForm::getExecGrade(void) const
{
	return (this->execGrade);
}

const std::string		ShrubberyCreationForm::getTarget(void) const
{
	return(this->target);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : target(target  + ".shrubbery"), name("Shrubbery Request"), signGrade(145), execGrade(137)
{
	std::cout << GREEN << "ShrubberyCreationForm Default Constructor Called" << NC << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	try
	{
		AForm::execute(executor);
	}
	catch(const std::exception& e)
	{
		throw;
		return ;
	}
	std::ofstream	fileName(this->getTarget().c_str());
	if (!fileName.is_open())
	{
		std::cout << "Open file error\n";
		return ;
	}
	fileName << "Test\n";
	fileName.close();
}

std::ostream &operator<<(std::ostream& os, ShrubberyCreationForm &Shrub)
{
	os << Shrub.getName() << " can only be signed by personnel with grade ";
	os << Shrub.getSignGrade() << " or higher\n  and it can only be executed by personnel with grade " << Shrub.getExecGrade();
	os << " or higher.\nThis document has a sign value of: " << std::boolalpha << Shrub.getSign() << "\n";
	return (os);
}
