#ifndef SCALECONVERTER_HPP
# define SCALECONVERTER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class ScaleConverter
{
	public:
		ScaleConverter();
		~ScaleConverter();
		ScaleConverter& operator=(const ScaleConverter &copy_a);
		ScaleConverter(const ScaleConverter &copy);

		static void	Convert(std::string str);
		std::string	checkType(std::string str);
		void		toDouble(ScaleConverter &conv, std::string str);
		void		toFloat(ScaleConverter &conv, std::string str);
		void		toInt(ScaleConverter &conv, std::string str);
		void		toChar(ScaleConverter &conv, std::string str);
		void		checkIsPrint(int i);
		void		checkImpossible(double d);

		class	NonDisplayableException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class ImpossibleException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class InvalidTypeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

};

#endif

