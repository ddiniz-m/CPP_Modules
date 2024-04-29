
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

std::pair<int, float>	BitcoinExchange::inputPair(std::string line)
{
	char	c = '\0';
	int		date = 0;
	float	value = 0;

	line = dateErase(line);

	std::istringstream iss(line);

	iss >> date >> c >> value;
	if (c != '|')
		value = 0;
	return (std::make_pair(date, value)); 
}

void	BitcoinExchange::dbInit(std::string line)
{
	char	c;
	int		date;
	float	value;

	line = dateErase(line);
	std::istringstream iss(line);

	if (iss >> date >> c >> value)
		db.insert(std::make_pair(date, value));
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
		if (line.compare("date | value") == 0)
			continue ;
		displayResult(inputPair(line));
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
		dbInit(line);
	}
}