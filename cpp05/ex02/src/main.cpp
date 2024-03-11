
#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int	main(void)
{
	{
		Bureaucrat	FBI(12, "FBI-man");
		Bureaucrat	Boss(1, "Boss-man");
		PresidentialPardonForm	Pardon;
		RobotomyRequestForm		Robot;

		std::cout << FBI << "\n";
		std::cout << Boss << "\n";
	}
	return (0);
}