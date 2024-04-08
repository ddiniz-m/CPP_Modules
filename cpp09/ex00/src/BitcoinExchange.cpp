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

std::multimap<int, double>	BitcoinExchange::getMap(void)
{
	return (this->m);
}

std::multimap<int, double>	BitcoinExchange::getDb(void)
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
	char	c;
	int		date;
	double	value;

	line = dateErase(line);

	std::istringstream iss(line);

	if (!(iss >> date >> c >> value))
	{
		if (value == -1)
			/* std::cout << "Error: too large a number => " << date << "\n" */;
		if (value > 1000)
			/* std::cout << "Error: too large a number => " << date << "\n" */;
	}
	else if (value < 0)
		/* std::cout << "Error: not a positive number => " << date << "\n" */;
	else
	{
		m.insert(std::make_pair(date, value));
	}
}

void	BitcoinExchange::fillDb(std::string line)
{
	char	c;
	int		date;
	double	value;

	line = dateErase(line);
	std::istringstream iss(line);

	if (iss >> date >> c >> value)
		db.insert(std::make_pair(date, value));
}

void	BitcoinExchange::printMap(std::multimap<int, double> map)
{
	std::multimap<int, double>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		std::cout << std::fixed << "Date: ";
		displayDate(it->first);
		std::cout << "; Value: " << std::setprecision(2) << it->second << "\n";
	}
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