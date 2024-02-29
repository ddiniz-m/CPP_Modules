
#include "../inc/ScaleConverter.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
ScaleConverter::ScaleConverter()
{
	std::cout << GREEN << "ScaleConverter Default Constructor Called" << NC << std::endl;
}

ScaleConverter& ScaleConverter::operator=(const ScaleConverter &copy_a)
{
	std::cout << GREEN << "ScaleConverter Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

ScaleConverter::ScaleConverter(const ScaleConverter &copy)
{
	std::cout << GREEN << "ScaleConverter Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

ScaleConverter::~ScaleConverter()
{
	std::cout << RED << "ScaleConverter Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

#include <stdio.h>
void	*ScaleConverter::Convert(std::string str)
{
	char	*cstr;

	cstr = (char *)str.c_str();
	printf("%s\n", cstr);
	for (int i = 0; i < (int)strlen(cstr); i++)
	{
		if((int)strlen(cstr) == 1 && isalpha(cstr[i]))
		{
			return (cstr);
		}
	}
	return (cstr);
}
