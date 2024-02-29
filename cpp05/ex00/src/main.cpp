
#include "../inc/ScaleConverter.hpp"

int	main(void)
{
	ScaleConverter	Conv;

	std::string	chr = "a";
	std::string	i = "42";
	std::string	f = "42.0f";
	std::string	d = "42.0";

	std::cout << "Character: " << Conv.Convert(chr) << "\n";
	std::cout << "Integer: " << Conv.Convert(i) << "\n";
	std::cout << "Float: " << Conv.Convert(f) << "\n";
	std::cout << "Double: " << Conv.Convert(d) << "\n";

}