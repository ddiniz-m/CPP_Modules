
#include "../inc/BitcoinExchange.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------

BitcoinExchange::BitcoinExchange()
{
	std::cout << GREEN << "BitcoinExchange Default Constructor Called" << NC << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &copy_a)
{
	std::cout << GREEN << "BitcoinExchange Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << GREEN << "BitcoinExchange Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------


const char	*BitcoinExchange::NegativeException::what() const throw()
{
	return("not a positive number");
}

const char	*BitcoinExchange::IntMaxException::what() const throw()
{
	return("too large a number");
}

const char	*BitcoinExchange::BadInputException::what() const throw()
{
	return("bad input");
}

std::multimap<int, float>	BitcoinExchange::getMap(void)
{
	return (this->input);
}

std::map<int, float>	BitcoinExchange::getDb(void)
{
	return (this->db);
}

/* void	BitcoinExchange::setDate()
{
	time_t	t;
	tm * now;
	
	t = time(0);
	now = localtime(&t);
	date += (now->tm_year + 1900) * 1000;
	if (now->tm_mon + 1 < 10)
		date *= 10;
	date += (now->tm_mon + 1) * 100;
	date += now->tm_mday;
} */

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

std::string	BitcoinExchange::dateErase(std::string line)
{
	for (std::string::iterator it = line.begin(); it < line.end() && *it != ' '; it++)
	{
		if (*it == '-')
			line.erase(it);
	}
	return (line);
}

void	BitcoinExchange::fillMap(std::string line)
{
	char	c = '\0';
	int		date = 0;
	float	value = 0;

	line = dateErase(line);

	std::istringstream iss(line);

	if (line.compare("date | value") == 0)
		return ;
	iss >> date >> c >> value;
	input.insert(std::make_pair(date, value));
}

void	BitcoinExchange::fillDb(std::string line)
{
	char	c;
	int		date;
	float	value;

	line = dateErase(line);
	std::istringstream iss(line);

	if (iss >> date >> c >> value)
		db.insert(std::make_pair(date, value));
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

int	digitCount(int i)
{
	if (i/10 == 0)
		return (1);
	return (1 + digitCount (i / 10));
}

int	badInput(std::multimap<int, float>::iterator it)
{
	if (digitCount(it->first) < 6)
	if (!it->first || !it->second)
		return (1);
	if (it->first / 100 % 100 > 12 || it->first / 100 % 100 <= 0)
		return (1);
	if (it->first % 100 > 31 || it->first % 100 <= 0)
		return (1);
	return (0);
}

void	BitcoinExchange::printMap(std::multimap<int, float> map)
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
			displayDate(it->first);
			std::cout << "\n";
			continue;
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: " << e.what() << '\n';
			continue;
		}
		displayDate(it->first);
		std::cout << " => " << it->second << " = ";
		displayAmount(it);
		std::cout << "\n";
	}
}

void	BitcoinExchange::printDb(std::map<int, float> db)
{
	std::map<int, float>::iterator it;
	for (it = db.begin(); it != db.end(); it++)
	{
		std::cout << "Date: ";
		displayDate(it->first);
		std::cout << "; Value: " << it->second << "\n";
	}
}

void	BitcoinExchange::readInput(char **av)
{
	std::string		line;
	std::fstream	file;

	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file.\n";
		return ;
	}
	while(getline(file, line))
	{
		fillMap(line);
	}
	printMap(input);
}

void	BitcoinExchange::readDb(void)
{
	std::fstream	db;
	std::string		line;

	db.open("data.csv", std::ios::in);
	if (!db.is_open())
	{
		std::cout << "Error: could not open file\n";
		return ;
	}

	while (!db.eof())
	{
		getline(db, line);
		fillDb(line);
	}
}