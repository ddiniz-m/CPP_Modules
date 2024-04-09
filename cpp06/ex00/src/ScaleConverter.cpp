
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

std::string		ScaleConverter::handlePseudo(std::string str)
{
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		return ("pseudo");
	else if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)	
		return ("pseudo");
	else
		throw InvalidTypeException();
	return (0);
}

void	ScaleConverter::Pseudo(ScaleConverter &conv, std::string str)
{
	std::cout << "char: Impossible" << "\n";
	std::cout << "int: Impossible" << "\n";
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
	(void)conv;
}

void	ScaleConverter::toChar(ScaleConverter &conv, std::string str)
{
	char	c = str[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	try
	{
		conv.checkIsPrint(c);
	}
	catch(const std::exception& e)
	{
		printException(i, f, d, e.what());
		return ;
	}
	printIntChar(i, c, f, d);
	return ;
}

void	ScaleConverter::toInt(ScaleConverter &conv, std::string str)
{
	int		i = std::atoi(str.c_str());
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	try
	{
		conv.checkImpossible(std::atof(str.c_str()));
		conv.checkIsPrint(i);
	}
	catch(const ImpossibleException& e)
	{
		printException2(e.what());
		return;
	}
	catch(const NonDisplayableException& e)
	{
		printException(i, f, d, e.what());
		return ;
	}
	printIntChar(i, c, f, d);
	return ;
}

void	ScaleConverter::toFloat(ScaleConverter &conv, std::string str)
{
	float	f = std::atof(str.c_str());
	char	c = static_cast<char>(f);
	int 	i = static_cast<int>(f);
	double	d = static_cast<double>(f);
	size_t	decimal = str.length() - str.find_first_of(".") - 2;

	try
	{
		conv.checkImpossible(std::atof(str.c_str()));
		conv.checkIsPrint(c);
	}
	catch(const ImpossibleException& e)
	{
		printException2(e.what());
		return ;
	}
	catch(const NonDisplayableException& e)
	{
		std::cout << "char: " << e.what() << "\n";
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
		std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << "\n";
		return ;
	}
	printFloatDouble(i, c, f, d, decimal);
	return ;
}
 
void	ScaleConverter::toDouble(ScaleConverter &conv, std::string str)
{
	double	d = std::atof(str.c_str());
	char	c = static_cast<char>(d);
	int		i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	size_t	decimal = str.length() - str.find_first_of(".") - 1;

	try
	{
		conv.checkImpossible(d);
		conv.checkIsPrint(d);
	}
	catch(const ImpossibleException& e)
	{
		printException2(e.what());
		return ;
	}
	catch(const NonDisplayableException& e)
	{
		std::cout << "char: " << e.what() << "\n";
		std::cout << "int: " << i << "\n";
		std::cout << "float: " << std::fixed << std::setprecision(decimal) << f << "f\n";
		std::cout  <<"double: " << std::fixed << std::setprecision(decimal) << d << "\n";
		return ;
	}
	printFloatDouble(i, c, f, d, decimal);
	return ;
}

std::string	ScaleConverter::checkType(std::string str)
{
	ScaleConverter Conv;
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
	else if((int)str.length() == 1)
	{
		return ("char");
	}
	else
		return (handlePseudo(str));
	return NULL;
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

	void	(ScaleConverter::*member_ptr[5])(ScaleConverter &conv, std::string str) = {
		&ScaleConverter::toChar,
		&ScaleConverter::toInt,
		&ScaleConverter::toFloat,
		&ScaleConverter::toDouble,
		&ScaleConverter::Pseudo
	};

	std::string types[5] = {"char", "int", "float", "double", "pseudo"};

	for (int i = 0; i < 5; i++)
	{
		if (type.compare(types[i]) == 0)
			(Conv.*member_ptr[i])(Conv, str);
	}
}