
#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	{
		try
		{
			Bureaucrat	FBI(12, "FBI-man");
			std::cout << FBI << "\n";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Bureaucrat	Boss(0, "Boss-man");
			std::cout << Boss << "\n";
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		try
		{
			Bureaucrat	Janitor(200, "Janitor-man");
			std::cout << Janitor;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		try
		{
			Bureaucrat	FBI(1,"FBI-man");
			std::cout << "Pre-Increment:\n" << FBI << "\n";
			FBI.Increment();
			std::cout << "Pos-Increment:\n" << FBI << "\n";
			std::cout << "Pre-Decrement:\n" << FBI << "\n";
			FBI.Decrement();
			std::cout << "Pos-Decrement:\n" << FBI;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		try
		{
			Bureaucrat	FBI(150, "FBI-man");
			std::cout << "Pre-Decrement:\n" << FBI << "\n";
			FBI.Decrement();
			std::cout << "Pos-Decrement:\n" << FBI << "\n";
			std::cout << "Pre-Increment:\n" << FBI << "\n";
			FBI.Increment();
			std::cout << "Pos-Increment:\n" << FBI;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		try
		{
			Bureaucrat	FBI(50, "FBI-man");
			std::cout << "Pre-Increment:\n" << FBI << "\n";
			FBI.Increment();
			std::cout << "Pos-Increment:\n" << FBI;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << YELLOW << "\n************************";
	std::cout << YELLOW << "************************\n\n";
	{
		try
		{
			Bureaucrat	FBI(50, "FBI-man");
			std::cout << "Pre-Decrement:\n" << FBI << "\n";
			FBI.Decrement();
			std::cout << "Pos-Decrement:\n" << FBI;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}