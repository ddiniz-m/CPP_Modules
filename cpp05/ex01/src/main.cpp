
#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	{
		Bureaucrat	FBI(12, "FBI-man");
		Bureaucrat	Boss(1, "Boss-man");
		Form		Nda("Non-Disclosure Agreement");

		std::cout << FBI << "\n";
		std::cout << Boss << "\n";

		std::cout << Nda << "\n";
		FBI.signForm(Nda);

		std::cout << Nda << "\n";
		Boss.signForm(Nda);

		std::cout << Nda << "\n";
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		Bureaucrat	FBI(0, "FBI-man");
		Bureaucrat	Boss(151, "Boss-man");
	}
	return (0);
}