
#include "../inc/sedbad.h"


/* 
	I use string.compare() and string.substr() to help me replace s1 for s2.
Getline delimiter is first character of s1. I then compare the first n characters of
each line to s1 (minus the fisrt character that was removed by getline).
*/
int	main(int ac, char **av)
{
	int				flag = 0;
	const char		*str2;
	std::string		str1;
	std::string		line;
	std::fstream	file;
	std::string		sub = std::string(av[2]);

	if (ac != 4)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return (0);
	}
	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Open file error" << std::endl;
		return (0);
	}
	str1 = replaceFilename(av[1]);
	str2 = str1.c_str();
	std::ofstream outfile (str2);
	while (!file.eof())
	{
		getline(file, line, av[2][0]);
		std::string sub2 = sub.substr(1);
		if (sub2.compare(line.substr(0, sub.length() - 1)) == 0 && flag != 0)
			outfile << std::string(av[3]) << line.substr(sub.length() - 1);
		else
		{
			if (flag != 0)
				outfile << av[2][0];
			outfile << line;
			flag++;
		}
	}
	file.close();
	outfile.close();
	printFile(av[1]);
	std::cout << std::endl;
	printFile(str2);
	return (0);
}	 