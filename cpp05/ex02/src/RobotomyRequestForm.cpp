
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : name(copy.name), signGrade(72), execGrade(45)
{
	std::cout << GREEN << "RobotomyRequestForm Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

std::string	RobotomyRequestForm::getName(void) const
{
	return(this->name);
}

bool		RobotomyRequestForm::getSign(void) const
{
	return(this->sign);
}

int			RobotomyRequestForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int			RobotomyRequestForm::getExecGrade(void) const
{
	return (this->execGrade);
}

std::string		RobotomyRequestForm::getTarget(void) const
{
	return(this->target);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : target(target), name("Robotomy Request"), signGrade(72), execGrade(45)
{
	std::cout << GREEN << "RobotomyRequestForm Default Constructor Called" << NC << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);
	}
	catch(const std::exception& e)
	{
		throw;
	}
	std::cout << GREEN << "RobotomyRequestForm is being executed..." << NC << "\n";
	std::cout << "*******HEAVEN PIERCING DRILLING NOISES*******\n";
	srand((unsigned) time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << "'s robotomy failed!\n";
	else
		std::cout << this->getTarget() << " has been robotomized!\n";
}

std::ostream &operator<<(std::ostream& os, RobotomyRequestForm &Robo)
{
	os << Robo.getName() << " can only be signed by personnel with grade ";
	os << Robo.getSignGrade() << " or higher\n  and it can only be executed by personnel with grade " << Robo.getExecGrade();
	os << " or higher.\nThis document has a sign value of: " << std::boolalpha << Robo.getSign() << "\n";
	return (os);
}