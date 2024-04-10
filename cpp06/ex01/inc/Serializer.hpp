#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <inttypes.h>
#include "Data.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer& operator=(const Serializer &copy_a);
		Serializer(const Serializer &copy);

	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);
};

#endif

