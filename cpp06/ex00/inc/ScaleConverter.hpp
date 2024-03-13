#ifndef SCALECONVERTER_HPP
# define SCALECONVERTER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>

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

		static void		Convert(std::string str);
		std::string		getType(std::string str);
};

#endif

