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

void	BitcoinExchange::displayAmount(std::pair<int, float> pair)
{
	std::map<int, float>::iterator		itDb;
	std::map<int, float>::iterator		prev;

	for (itDb = db.begin(), prev = itDb; itDb != db.end(); prev = itDb, itDb++)
	{
		if (pair.first == itDb->first)
		{
			std::cout << pair.second * itDb->second;
			return ;
		}
		if (pair.first - itDb->first < 0)
			break ;
	}
	std::cout << pair.second * prev->second;
}

void	BitcoinExchange::displayBadException(std::pair<int, float> pair)
{
	if (pair.second == 0)
		std::cout << "Wrong format";
	else if (digitCount(pair.first) != 8)
		std::cout << "Wrong date format";
	else if (pair.first / 100 % 100 == 02 && pair.first % 100 == 29 && !leapYear(pair.first / 10000))
	{
		std::cout << "Date does not exist (not a leap year): ";
		displayDate(pair.first);
	}
	else
	{
		std::cout << "Date does not exist: ";
		displayDate(pair.first);
	}
	std::cout << "\n";
}

void	BitcoinExchange::displayResult(std::pair<int, float> pair)
{
	try
	{
		if (badInput(pair))
			throw BadInputException();
		if (pair.second < 0)
			throw NegativeException();
		if (pair.second > 1000)
			throw IntMaxException();
	}
	catch(const BadInputException &e)
	{
		std::cout << "Error: " << e.what() << " => ";
		displayBadException(pair);
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '\n';
		return ;
	}
	displayDate(pair.first);
	std::cout << " => " << std::fixed << std::setprecision(sizeof(pair.second) / 4);
	std::cout << pair.second << " = ";
	displayAmount(pair);
	std::cout << "\n";
}