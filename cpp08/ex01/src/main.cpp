#include "../inc/Span.hpp"

int	main(void)
{
	{
		Span span(10);

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
		span.longestSpan();
		span.shortestSpan();
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
		span.longestSpan();
		span.shortestSpan();
	}
	std::cout << MAGENTA << "\n********************SCOPE********************\n\n" << NC;
	{
		Span span(10000);
		std::vector<int>v(9998, 42);

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
		span.longestSpan();
		span.shortestSpan();
	}
}