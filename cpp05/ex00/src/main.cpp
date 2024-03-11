
#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	{
		Bureaucrat	FBI(12, "FBI-man");
		Bureaucrat	Boss(0, "Boss-man");
		Bureaucrat	Janitor(200, "Janitor-man");

		std::cout << FBI << "\n";
		std::cout << Boss << "\n";
		std::cout << Janitor;
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		Bureaucrat	FBI(1,"FBI-man");
		std::cout << "Pre-Increment:\n" << FBI << "\n";
		FBI.Increment();
		std::cout << "Pos-Increment:\n" << FBI << "\n";
		std::cout << "Pre-Decrement:\n" << FBI << "\n";
		FBI.Decrement();
		std::cout << "Pos-Decrement:\n" << FBI;
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		Bureaucrat	FBI(150, "FBI-man");
		std::cout << "Pre-Decrement:\n" << FBI << "\n";
		FBI.Decrement();
		std::cout << "Pos-Decrement:\n" << FBI << "\n";
		std::cout << "Pre-Increment:\n" << FBI << "\n";
		FBI.Increment();
		std::cout << "Pos-Increment:\n" << FBI;
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		Bureaucrat	FBI(50, "FBI-man");
		std::cout << "Pre-Increment:\n" << FBI << "\n";
		FBI.Increment();
		std::cout << "Pos-Increment:\n" << FBI;
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		Bureaucrat	FBI(50, "FBI-man");
		std::cout << "Pre-Decrement:\n" << FBI << "\n";
		FBI.Decrement();
		std::cout << "Pos-Decrement:\n" << FBI;
	}

	return (0);
}