
#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	{
		Bureaucrat	Bu(12);
		Bu.setName("Saturn");

		std::cout << "Name: " << Bu.getName() << "\n";
		std::cout << "Grade: " << Bu.getGrade() << "\n\n";
	}
	{
		Bureaucrat	Bu(0);
		std::cout << "Grade: " << Bu.getGrade() << "\n\n";
	}
	{
		Bureaucrat	Bu(200);
		std::cout << "Grade: " << Bu.getGrade() << "\n\n";
	}
	{
		Bureaucrat	Bu(1);
		std::cout << "Grade Pre-Increment: " << Bu.getGrade() << "\n";
		Bu.Increment();
		std::cout << "Grade Pos-Increment: " << Bu.getGrade() << "\n";
		std::cout << "Grade Pre-Decrement: " << Bu.getGrade() << "\n";
		Bu.Decrement();
		std::cout << "Grade Pos-Decrement: " << Bu.getGrade() << "\n\n";
	}
	{
		Bureaucrat	Bu(150);
		std::cout << "Grade Pre-Decrement: " << Bu.getGrade() << "\n";
		Bu.Decrement();
		std::cout << "Grade Pos-Decrement: " << Bu.getGrade() << "\n";
		std::cout << "Grade Pre-Increment: " << Bu.getGrade() << "\n";
		Bu.Increment();
		std::cout << "Grade Pos-Increment: " << Bu.getGrade() << "\n\n";

	}
	{
		Bureaucrat	Bu(50);
		std::cout << "Grade Pre-Increment: " << Bu.getGrade() << "\n";
		Bu.Increment();
		std::cout << "Grade Pos-Increment: " << Bu.getGrade() << "\n\n";
	}
	{
		Bureaucrat	Bu(50);
		std::cout << "Grade Pre-Decrement: " << Bu.getGrade() << "\n";
		Bu.Decrement();
		std::cout << "Grade Pos-Decrement: " << Bu.getGrade() << "\n";
	}

	return (0);
}