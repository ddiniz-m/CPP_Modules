
#include "../inc/RobotomyRequestForm.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
RobotomyRequestForm::RobotomyRequestForm() : name("Robotomy Request"), signGrade(72), execGrade(45)
{
	std::cout << GREEN << "RobotomyRequestForm Default Constructor Called" << NC << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy_a)
{
	std::cout << GREEN << "RobotomyRequestForm Copy Assignment Operator Called" << NC << std::endl;
	this->sign = copy_a.sign;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : name("Robotomy Request"), signGrade(72), execGrade(45)
{
	std::cout << GREEN << "RobotomyRequestForm Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target), name("Robotomy Request"), signGrade(72), execGrade(45)
{
	std::cout << GREEN << "RobotomyRequestForm Default Constructor Called" << NC << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	;
}