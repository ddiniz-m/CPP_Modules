#include "../inc/easyfind.hpp"
#include <vector>

int	main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	try
	{
		std::cout << easyfind(v, 3) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << easyfind(v, 11) << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
