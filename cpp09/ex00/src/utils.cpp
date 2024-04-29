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

std::string	dateErase(std::string line)
{
	for (std::string::iterator it = line.begin(); it < line.end() && *it != ' '; it++)
	{
		if (*it == '-')
			line.erase(it);
	}
	return (line);
}

int	badInput(std::pair<int, float> pair)
{
	if (!pair.first || !pair.second)
		return (1);
	if (pair.first / 100 % 100 == 02 && pair.first % 100 == 29 && !leapYear(pair.first / 10000))
		return (1);
	if (digitCount(pair.first) > 8)
		return (1);
	if (pair.first / 100 % 100 > 12 || pair.first / 100 % 100 <= 0)
		return (1);
	if (pair.first % 100 > 31 || pair.first % 100 <= 0)
		return (1);
	return (0);
}