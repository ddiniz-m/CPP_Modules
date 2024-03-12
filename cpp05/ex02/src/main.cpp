
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

		PresidentialPardonForm	President;
		RobotomyRequestForm		Robot;
		ShrubberyCreationForm	Shrub("Home");

		std::cout << FBI;
		std::cout << Boss << "\n";
		std::cout << President << "\n";

		Boss.signForm(President);
		Boss.signForm(Robot);
		Boss.signForm(Shrub);

		Boss.executeForm(President);
		Boss.executeForm(Robot);
		Boss.executeForm(Shrub);


	}
	return (0);
}