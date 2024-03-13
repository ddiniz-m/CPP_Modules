
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

void	toFloat(std::string str)
{
	float	f;
	std::stringstream ss;
	ss << str;
	ss >> f;

	std::cout << "f: " << f << "\n";
	std::cout << "Char: " << static_cast<char>(f) << "\n";
	std::cout << "Int: " << static_cast<int>(f) << "\n";
	std::cout << "Float: " << f << "\n";
	std::cout << "Double: " << static_cast<double>(f) << "\n";
}

void	toInt(std::string str)
{
	int	i;

	i = std::atoi(str.c_str());
	std::cout << "Char: " << static_cast<char>(i) << "\n";
	std::cout << "Int: " << i << "\n";
	std::cout << "Float: " << static_cast<float>(i) << "\n";
	std::cout << "Double: " << static_cast<double>(i) << "\n";
}

void	toDouble(std::string str)
{
	double	d;

	d = std::atof(str.c_str());
	std::cout << "Char: " << static_cast<char>(d) << "\n";
	std::cout << "Int: " << static_cast<int>(d) << "\n";
	std::cout << "Float: " << static_cast<float>(d) << "\n";
	std::cout << "Double: " << d << "\n";
}

void	toChar(std::string str)
{
	char	c;

	c = str[0];
	std::cout << "Char: " << c << "\n";
	std::cout << "Int: " << (static_cast<int>(c)) << "\n";
	std::cout << "Float: " << static_cast<float>(c) << "\n";
	std::cout << "Double: " << static_cast<double>(c) << "\n";
}

std::string	ScaleConverter::getType(std::string str)
{
	int	i = 0;
	int	flag = 0;

	if (str[i] == '-')
		i++;
	if((int)str.length() == 1 && isalpha(str[i]))
	{
		return ("char");
	}
	if (str[i] && isdigit(str[i]))
	{
		while (i < (int)str.length())
		{
			if (str[i] == '.' && i + 1 < (int)str.length() && isdigit(str[i + 1]))
				flag++;
			else if (flag == 1 && i == (int)str.length() - 1 && str[i] == 'f')
				return ("float");
			else if (!isdigit(str[i]) || flag > 1)
				return (NULL);
			i++;
		}
		if (flag == 1)
			return ("double");
		return ("int");
	}
	return ("Non displayable");
}

void	ScaleConverter::Convert(std::string str)
{
	ScaleConverter	Conv;
	std::string	type;

	type = Conv.getType(str);
	std::cout << "Type: " << type << "\n";
	if (type.compare("char") == 0)
	{
		toChar(str);
	}
	else if (type.compare("int") == 0)
	{
		toInt(str);
	}
	else if (type.compare("float") == 0)
	{
		toFloat(str);
	}
	else if (type.compare("double") == 0)
	{
		toDouble(str);
	}
	else
		std::cout << "Invalid Scalar type\n";
}
