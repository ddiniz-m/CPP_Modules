#include "../inc/Span.hpp"

int	main(void)
{
	{
		Span	span(10);

		try
		{
			for (int i = 0; i < 11; i++)
			{
				span.addNumber(i);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.vectorPrint();
		std::cout << span.longestSpan() << "\n";
		std::cout << span.shortestSpan() << "\n";
	}
	std::cout << MAGENTA << "\n********************SCOPE********************\n\n" << NC;
	{
		Span span(10);

		try
		{
			span.addNumber(1);
			span.addNumber(10);
			span.addNumber(20);
			span.addNumber(100);
			span.addNumber(83);
			span.addNumber(32);
			span.addNumber(12312);
			span.addNumber(87);
			span.addNumber(123);
			span.addNumber(902);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.vectorPrint();
		std::cout << span.longestSpan() << "\n";
		std::cout << span.shortestSpan() << "\n";
	}
	std::cout << MAGENTA << "\n********************SCOPE********************\n\n" << NC;
	{
		Span span(20000);
		std::vector<int>v(19998, 42);

		try
		{
			span.addNumber(1);
			span.addRange(v.begin(), v.end());
			span.addNumber(1000);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		span.vectorPrint();
		std::cout << span.longestSpan() << "\n";
		std::cout << span.shortestSpan() << "\n";
	}
	std::cout << MAGENTA << "\n********************SCOPE********************\n\n" << NC;
	{
		Span				s(10);
		std::vector<int>	v(5, 1);

		s.addRange(v.begin(), v.end());
		s.vectorPrint();

		Span	copy(s);
		std::cout << copy.getCapacity() << "\n";
		copy.vectorPrint();

		Span	assign;
		assign = s;
		std::cout << assign.getCapacity() << "\n";
		assign.vectorPrint();

	}
}