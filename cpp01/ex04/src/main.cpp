
#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	(void)ac;
	std::string		buf;
	std::fstream	file;
	file.open(av[1], std::ios::in);
	if (!file)
	{
		std::cout << "Open file error" << std::endl;
		return (0);
	}
	while (!file.eof())
	{
		getline(file, buf, av[2][0]);
		std::cout << buf << std::endl;
	}
	file.close();
	return (0);
}	