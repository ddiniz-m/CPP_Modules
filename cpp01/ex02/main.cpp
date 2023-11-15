
#include <iostream>

int	main(void)
{
	std::string		string;
	std::string		*stringPTR;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;

	std::string		&stringREF = string;;

	std::cout << "STR Address: " << &string << std::endl;
	std::cout << "PTR Address: " << &stringPTR << std::endl;
	std::cout << "REF Address: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "STR Value: " << string << std::endl;
	std::cout << "PTR Value: " << stringPTR << std::endl;
	std::cout << "REF Value: " << stringREF << std::endl;
}