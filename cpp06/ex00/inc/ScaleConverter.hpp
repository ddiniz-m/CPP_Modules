#ifndef SCALECONVERTER_HPP
# define SCALECONVERTER_HPP

#include <iostream>
#include <cstring>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class ScaleConverter
{
	public:
		ScaleConverter();
		virtual ~ScaleConverter();
		ScaleConverter& operator=(const ScaleConverter &copy_a);
		ScaleConverter(const ScaleConverter &copy);

		static void	Convert(char *str);
		const char	*getType(char *str);
};

#endif
