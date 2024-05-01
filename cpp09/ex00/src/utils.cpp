#include "../inc/BitcoinExchange.hpp"

int	leapYear(int i)
{
	if (i % 4 == 0)
	{
		if (i % 100 == 0 && i % 400 == 0)
			return (1);
		if (i % 100 == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	digitCount(int i)
{
	if (i / 10 == 0)
		return (1);
	return (1 + digitCount (i / 10));
}

int	dateCheck(std::string line)
{
	std::string			date;
	char				c = '\0';
	int					year = 0;
	std::istringstream	iss(line);
	int					digits = 0;

	iss >> year >> c >> date;
	if (digitCount(year) != 4)
		return (1);
	for (std::string::iterator it = date.begin(); it < date.end(); it++)
	{
		if (isdigit(*it))

			digits++;
		if (*it == '-' && digits == 2)
			digits = 0;
	}
	return (digits != 2);
}

std::string	dateErase(std::string line)
{
	int	dash = 0;
	for (std::string::iterator it = line.begin(); it < line.end() && *it != ' '; it++)
	{
		if (*it == '-')
		{
			dash++;
			line.erase(it);
		}
	}
	if (dash != 2)
		line.clear();
	return (line);
}