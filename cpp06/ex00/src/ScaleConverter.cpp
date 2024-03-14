
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
	if (!std::isprint(i))
		throw NonDisplayableException();
}

void	ScaleConverter::checkImpossible(int i)
{
	if (i > 2147483647 || i < -2147483648)
		throw ImpossibleException();
}

int		checkPseudo(std::string str)
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 ||str.compare("nanf") == 0)
		return (1);
	if (str.compare("-inf") == 0 ||str.compare("+inf") == 0 ||str.compare("nan") == 0)	
		return (1);
	return (0);
}

void	ScaleConverter::toChar(std::string str)
{
	int	i = strtod(str.c_str(), NULL);
	try
	{
		if (!std::isprint(i))
			throw NonDisplayableException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

void	ScaleConverter::toInt(std::string str)
{

	return ;
}

void	ScaleConverter::toFloat(std::string str)
{

	return ;
}
 
void	ScaleConverter::toDouble(std::string str)
{
	return ;
}

std::string	ScaleConverter::checkType(std::string str)
{
	ScaleConverter Conv;
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
			{
				return ("float");
			}
			else if (!isdigit(str[i]) || flag > 1)
				throw InvalidTypeException();
			i++;
		}
		if (flag == 1)
			return ("double");
		return ("int");
	}
	throw InvalidTypeException();
}

void	ScaleConverter::Convert(std::string str)
{
	ScaleConverter	Conv;
	std::string		type;

	try
	{
		type = Conv.checkType(str);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return ;
	}

	void	(ScaleConverter::*member_ptr[4])(std::string str) = {
		&ScaleConverter::toChar,
		&ScaleConverter::toInt,
		&ScaleConverter::toFloat,
		&ScaleConverter::toDouble
	};

	std::string types[4] = {"char", "int", "float", "double"};

	for (int i = 0; i < 4; i++)
	{
		if (type.compare(types[i]) == 0)
			(Conv.*member_ptr[i])(str);
	}
}