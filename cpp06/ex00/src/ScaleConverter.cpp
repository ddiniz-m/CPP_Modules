
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

const char	*ScaleConverter::getType(char *str)
{
	int	i = 0;
	int	flag = 0;

	if (str[i] == '-')
		i++;
	if((int)strlen(str) == 1 && isalpha(str[i]))
	{
		return ("char");
	}
	if (str[i] && isdigit(str[i]))
	{
		while (i < (int)strlen(str))
		{
			if (str[i] == '.' && i + 1 < (int)strlen(str) && isdigit(str[i + 1]))
				flag++;
			else if (flag == 1 && i == (int)strlen(str) - 1 && str[i] == 'f')
				return ("float");
			else if (!isdigit(str[i]) || flag > 1)
				return (NULL);
			i++;
		}
		if (flag == 1)
			return ("double");
		return ("int");
	}
	return (NULL);
}

void	ScaleConverter::Convert(char *str)
{
	ScaleConverter	Conv;
	const char		*type;

	type = Conv.getType(str);
	if (!type)
		std::cout << "Invalid Scalar type\n";
	if (strcmp(type, "char") == 0)
		;
	if (strcmp(type, "int") == 0)
		;
	if (strcmp(type, "float") == 0)
		;
	if (strcmp(type, "double") == 0)
		;
	if (type)
		std::cout << "Type: " << type << "\n";
}
