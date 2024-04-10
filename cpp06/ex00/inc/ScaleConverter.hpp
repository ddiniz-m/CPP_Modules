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
	private:
		ScaleConverter();
		~ScaleConverter();

	public:
		ScaleConverter& operator=(const ScaleConverter &copy_a);
		ScaleConverter(const ScaleConverter &copy);

		static	void		Convert(std::string str);
		static	void		checkType(std::string str);
		static	void		handlePseudo(std::string str);
		static	void		Pseudo(std::string str);
		static	void		toDouble(ScaleConverter &conv, std::string str);
		static	void		toFloat(ScaleConverter &conv, std::string str);
		static	void		toInt(ScaleConverter &conv, std::string str);
		static	void		toChar(ScaleConverter &conv, std::string str);
		static	void		checkIsPrint(int i);
		static	void		checkImpossible(double d);

		class	NonDisplayableException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	ImpossibleException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	InvalidTypeException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

};

void		printException(int i, float f, double d, const char *e);
void		printException2(const char *e);
void		printIntChar(int i, char c, float f, double d);
void		printFloatDouble(int i, char c, float f, double d, size_t decimal);

#endif

