#include "../inc/ScaleConverter.hpp"

void	printIntChar(int i, char c, float f, double d)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void	printFloatDouble(int i, char c, float f, double d, size_t decimal)
{
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
	std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << "\n";
}

void	printException(int i, float f, double d, const char *e)
{
	std::cout << "char: " << e << "\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

void	printException2(const char *e)
{
	std::cout << "char: " << e << "\n";
	std::cout << "int: " << e << "\n";
	std::cout << "float: " << e << "\n";
	std::cout << "double: " << e << "\n";
}
