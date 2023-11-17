
#include "../inc/sedbad.h"

void	printFile(const char *filename)
{
	std::string line;
	std::ifstream file(filename);

	std::cout << GREEN << filename << NC << " contents:"<<std::endl;
	while (!file.eof())
	{
		getline(file, line);
		std::cout << line << std::endl;
	}
	file.close();
}

std::string	replaceFilename(char *filename)
{
	std::string	str(filename);
	std::string	suf(".replace");
	std::string join(str + suf);

	return (join);
}