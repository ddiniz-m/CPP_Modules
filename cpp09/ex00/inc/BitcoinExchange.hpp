#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include <cstdlib>
#include <string>
#include <sstream>
#include <exception>
#include <iomanip>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class BitcoinExchange : public std::map<int, double>
{
	private:
		std::multimap<int, double>	m;
		std::multimap<int, double>	db;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange &copy_a);
		BitcoinExchange(const BitcoinExchange &copy);

		void						setDate(void);
		std::multimap<int, double>	getMap(void);
		std::multimap<int, double>	getDb(void);

		void			printMap(std::multimap<int, double> map);
		void			displayDate(const int i);
		void			fillMap(std::string line);
		void			fillDb(std::string line);
		std::string		dateErase(std::string line);
		void			readDb(void);

		class	NegativeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	IntMaxException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	BadInputException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif

