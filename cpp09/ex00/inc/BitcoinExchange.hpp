#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include <cstdlib>
#include <string>
#include <sstream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

template <typename T>
class BitcoinExchange : public std::map<int, T>
{
	private:
		std::map<int, T> m;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange &copy_a);
		BitcoinExchange(const BitcoinExchange &copy);

		void	setDate(void);
		void	printMap(void);

		void	displayDate(const int i);
		void	fillMap(std::string line);
};

// ---------------------- Orthodox Canonical Form -----------------------------
template <typename T>
BitcoinExchange<T>::BitcoinExchange()
{
	std::cout << GREEN << "BitcoinExchange Default Constructor Called" << NC << std::endl;
}

template <typename T>
BitcoinExchange<T>& BitcoinExchange<T>::operator=(const BitcoinExchange<T> &copy_a)
{
	std::cout << GREEN << "BitcoinExchange Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

template <typename T>
BitcoinExchange<T>::BitcoinExchange(const BitcoinExchange<T> &copy)
{
	std::cout << GREEN << "BitcoinExchange Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

template <typename T>
BitcoinExchange<T>::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

/* template <typename T>
void	BitcoinExchange<T>::setDate()
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

template <typename T>
void	BitcoinExchange<T>::displayDate(const int i)
{
	std::cout << i / 10000 << "-";
	if (i / 100 % 100 < 10)
		std::cout << '0';
	std::cout << i / 100 % 100 << "-";
	if (i % 100 < 10)
		std::cout << '0';
	std::cout << i % 100;
}

template <typename T>
void	BitcoinExchange<T>::fillMap(std::string line)
{
	int	date;
	char c;
	T	value;

	for (std::string::iterator it = line.begin(); it < line.end() && *it != ' '; it++)
	{
		if (*it == '-')
			line.erase(it);
	}
	std::istringstream iss(line);

	iss >> date >> c >> value;
	m.insert(std::make_pair(date, value));
}

template <typename T>
void	BitcoinExchange<T>::printMap(void)
{
	typename std::map<int, T>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		std::cout << "Date: "<< it->first << "\nValue: " << it->second << "\n";
	}
}

#endif

