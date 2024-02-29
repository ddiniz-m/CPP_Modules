#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice& operator=(const Ice &copy_a);
		Ice(const Ice &copy);

		void use(ICharacter& target);
		AMateria* clone() const;
};

#endif