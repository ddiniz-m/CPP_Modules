
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

void		BitcoinExchange::setLowestDate(int date)
{
	lowestDate = date;
}

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
	char	e = '\0';
	int		date = 0;
	float	value = 0;

	if (dateCheck(line) != 0)
		line.clear();
	else
		line = dateErase(line);

	std::istringstream iss(line);

	iss >> date >> c >> value >> e;
	if (c != '|' || (e && e != 'f'))
	{
		value = 0;
	}
	return (std::make_pair(date, value)); 
}

int	BitcoinExchange::badInput(std::pair<int, float> pair)
{
	if (!pair.first || !pair.second)
		return (1);
	if (pair.first / 100 % 100 == 02 && pair.first % 100 == 29 && !leapYear(pair.first / 10000))
		return (1);
	if (digitCount(pair.first) > 8 || pair.first < lowestDate)
		return (1);
	if (pair.first / 100 % 100 > 12 || pair.first / 100 % 100 <= 0)
		return (1);
	if (pair.first % 100 > 31 || pair.first % 100 <= 0)
		return (1);
	return (0);
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
	if (digitCount(date) == 8 && !lowestDate)
		setLowestDate(date);
}

void	BitcoinExchange::readInput(char **av)
{ 
	std::string		line;
	std::fstream	file;

	file.open(av[1], std::ios::in);
	if (!file.is_open())
	{
		std::cout << "Error: could not open input file.\n";
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
	std::fstream	dataBase;
	std::string		line;

	setLowestDate(0);
	dataBase.open("data.csv", std::ios::in);
	if (!dataBase.is_open())
	{
		std::cout << "Error: could not open database.\n";
		return ;
	}

	while (!dataBase.eof())
	{
		getline(dataBase, line);
		dbInit(line);
	}

}