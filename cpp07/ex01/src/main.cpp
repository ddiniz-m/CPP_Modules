
#include "../inc/Iter.hpp"

int	main()
{
	int	arr[10] = {'a','b','c','d','e','f','g','h','i','j'};

	::iter(arr, 10, myPrint<char>);

	std::cout << "\n";

	std::string str[4] = {"char", "int", "float", "double"};

	::iter(str, 4, myPrint<std::string>);
}