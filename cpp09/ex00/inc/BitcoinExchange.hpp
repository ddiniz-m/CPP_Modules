#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include <string>

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
		int		getDate(void);
		void	setValue(T& val);
		T		&getValue(void);

		void	displayDate(void);
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

template <typename T>
void	BitcoinExchange<T>::setDate( void )
{
	time_t	t;
	tm * now;
	
	t = time(0);
	now = localtime(&t);
	this->date += (now->tm_year + 1900) * 1000;
	if (now->tm_mon + 1 < 10)
		this->date *= 10;
	this->date += (now->tm_mon + 1) * 100;
	this->date += now->tm_mday;
}

template <typename T>
void	BitcoinExchange<T>::displayDate(void)
{
	std::cout << date << "\n";
	std::cout << date / 10000 << "-";
	if (date / 100 % 100 < 10)
		std::cout << '0';
	std::cout << date / 100 % 100 << "-";
	if (date % 100 < 10)
		std::cout << '0';
	std::cout << date % 100 << "\n";}

template <typename T>
int	BitcoinExchange<T>::getDate(void)
{
	return (this->date);
}

template <typename T>
void	BitcoinExchange<T>::setValue(T& val)
{
	(void)val;
}

template <typename T>
T		&BitcoinExchange<T>::getValue(void)
{
	return (this->value);
}

template <typename T>
void	BitcoinExchange<T>::fillMap(std::string line)
{
	int	date;
	T	value;

	std::cout << "DATE:\nINT CONVERSION: " << line.substr(0, line.find_first_of('|', 0)) << "\n";
	date = atoi(line.substr(0, line.find_first_of('|', 0)));
	std::cout << "to: " << date << "\n";

	std::cout << "VALUE:\nT CONVERSION: " << line.substr(line. substr(line.find_first_of('|', 0)), '\0') << "\n";
	value = atof(line. substr(line.find_first_of('|', 0)), '\0');
	std::cout << "to: " << value << "\n";

	m<int, T> = {date, value};
}

#endif

