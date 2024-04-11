#include "../inc/BitcoinExchange.hpp"

void	BitcoinExchange::displayDate(const int i)
{
	std::cout << i / 10000 << "-";
	if (i / 100 % 100 < 10)
		std::cout << '0';
	std::cout << i / 100 % 100 << "-";
	if (i % 100 < 10)
		std::cout << '0';
	std::cout << i % 100;
}

void	BitcoinExchange::displayAmount(std::multimap<int, float>::iterator it)
{
	std::map<int, float>::iterator		itDb;
	std::map<int, float>::iterator		prev;

	for (itDb = db.begin(), prev = itDb; itDb != db.end(); prev = itDb, itDb++)
	{
		if (it->first == itDb->first)
		{
			std::cout << it->second * itDb->second;
			return ;
		}
		if (it->first - itDb->first < 0)
			break ;
	}
	std::cout << it->second * prev->second;
}

void	BitcoinExchange::displayBadException(std::multimap<int, float>::iterator it)
{
	if (digitCount(it->first) != 8)
		std::cout << "Wrong date format";
	else if (it->first / 100 % 100 == 02 && it->first % 100 == 29 && !leapYear(it->first / 10000))
	{
		std::cout << "Date does not exist (not a leap year): ";
		displayDate(it->first);
	}
	else if (it->second == 0)
		std::cout << "Wrong format";
	else
	{
		std::cout << "Date does not exist: ";
		displayDate(it->first);
	}
	std::cout << "\n";
}

void	BitcoinExchange::displayResult(std::multimap<int, float> map)
{
	std::multimap<int, float>::iterator	it;
	
	for (it = map.begin(); it != map.end(); it++)
	{
		try
		{
			if (badInput(it))
				throw BadInputException();
			if (it->second < 0)
				throw NegativeException();
			if (it->second > 1000)
				throw IntMaxException();
		}
		catch(const BadInputException &e)
		{
			std::cout << "Error: " << e.what() << " => ";
			displayBadException(it);
			continue;
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: " << e.what() << '\n';
			continue;
		}
		displayDate(it->first);
		std::cout << " => " << std::fixed << std::setprecision(sizeof(it->second) / 4);
		std::cout << it->second << " = ";
		displayAmount(it);
		std::cout << "\n";
	}
}