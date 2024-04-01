#include "../inc/BitcoinExchange.hpp"

//map<key, value>

int	main(int ac, char **av)
{
	if (ac > 2)
	{
		std::cout << "Incorrect amount of arguments.\n";
		return (1);
	}

	std::string				line;
	std::fstream			file;
	BitcoinExchange<int>	bcn;

	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file.\n";
		return (1);
	}

	while(!file.eof())
	{
		getline(file, line);
		bcn.fillMap(line);
	}
	bcn.setDate();
	return (0);
}