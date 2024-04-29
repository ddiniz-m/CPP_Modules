#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class BitcoinExchange : public std::map<int, float>
{
	private:
		std::map<int, float>		db;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange &copy_a);
		BitcoinExchange(const BitcoinExchange &copy);

		std::pair<int, float>	inputPair(std::string line);
		void					dbInit(std::string line);
		void					readDb(void);
		void					readInput(char **av);

		void					displayResult(std::pair<int, float> pair);
		void					displayAmount(std::pair<int, float> pair);
		void					displayBadException(std::pair<int, float> pair);
		void					displayDate(const int i);

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

//utils.cpp
int				leapYear(int i);
int				digitCount(int i);
std::string		dateErase(std::string line);
int				badInput(std::pair<int, float> pair);

#endif

