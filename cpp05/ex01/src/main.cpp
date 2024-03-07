
#include "../inc/Form.hpp"

int	main(void)
{
	{
		Bureaucrat	FBI(12, "FBI-man");

		std::cout << FBI << "\n";
	}
	{
		Bureaucrat	FBI(0, "FBI-man");
		std::cout << FBI << "\n";
	}
	{
		Bureaucrat	FBI(200, "FBI-man");
		std::cout << FBI << "\n";
	}
	{
		Bureaucrat	FBI(1,"FBI-man");
		std::cout << "Pre-Increment:\n" << FBI << "\n";
		FBI.Increment();
		std::cout << "Pos-Increment:\n" << FBI << "\n";
		std::cout << "Pre-Decrement:\n" << FBI << "\n";
		FBI.Decrement();
		std::cout << "Pos-Decrement:\n" << FBI << "\n";
	}
	{
		Bureaucrat	FBI(150, "FBI-man");
		std::cout << "Pre-Decrement:\n" << FBI << "\n";
		FBI.Decrement();
		std::cout << "Pos-Decrement:\n" << FBI << "\n";
		std::cout << "Pre-Increment:\n" << FBI << "\n";
		FBI.Increment();
		std::cout << "Pos-Increment:\n" << FBI << "\n";

	}
	{
		Bureaucrat	FBI(50, "FBI-man");
		std::cout << "Pre-Increment:\n" << FBI << "\n";
		FBI.Increment();
		std::cout << "Pos-Increment:\n" << FBI << "\n";
	}
	{
		Bureaucrat	FBI(50, "FBI-man");
		std::cout << "Pre-Decrement:\n" << FBI << "\n";
		FBI.Decrement();
		std::cout << "Pos-Decrement:\n" << FBI << "\n";
	}

	return (0);
}