
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

const char	*ScaleConverter::ImpossibleException::what() const throw()
{
	return("impossible");
}

const char	*ScaleConverter::NonDisplayableException::what() const throw()
{
	return("Non displayable");
}

const char	*ScaleConverter::InvalidTypeException::what() const throw()
{
	return("Invalid Type");
}

void	ScaleConverter::checkIsPrint(int i)
{
	if (i > 126 || i < 33)
		throw NonDisplayableException();
}

void	ScaleConverter::checkImpossible(double d)
{
	if (d > 2147483647 || d < -2147483648)
		throw ImpossibleException();
}

void		ScaleConverter::handlePseudo(std::string str)
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		ScaleConverter::Pseudo(str);
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)	
		ScaleConverter::Pseudo(str);
	else
		throw InvalidTypeException();
	return ;
}

void	ScaleConverter::Pseudo(std::string str)
{
	std::cout << "char: impossible" << "\n";
	std::cout << "int: impossible" << "\n";
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
	{
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str.erase(str.length() - 1) << "\n";
	}
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)	
	{
		std::cout << "float: " << str << "f\n";
		std::cout << "double: " << str << "\n";
	}
}

void	ScaleConverter::checkType(std::string str)
{
	ScaleConverter	Conv;
	int	i = 0;
	int	flag = 0;

	if (str[i] == '-')
		i++;
	if (str[i] && str.find_first_not_of("-0123456789.f") == str.npos)
	{
		while (i < (int)str.length())
		{
			if (str[i] == '.' && i + 1 < (int)str.length() && isdigit(str[i + 1]))
				flag++;
			else if (flag == 1 && i == (int)str.length() - 1 && str[i] == 'f')
			{
				ScaleConverter::toFloat(Conv, str);
				return ;
			}
			else if (!isdigit(str[i]) || flag > 1)
				throw InvalidTypeException();
			i++;
		}
		if (flag == 1)
		{
			ScaleConverter::toDouble(Conv, str);
			return ;
		}
		ScaleConverter::toInt(Conv, str);
	}
	else if((int)str.length() == 1)
	{
		ScaleConverter::toChar(Conv, str);
	}
	else
		handlePseudo(str);
	return ;
}

void	ScaleConverter::Convert(std::string str)
{
	ScaleConverter	Conv;
	std::string		type;

	try
	{
		checkType(str);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}
}