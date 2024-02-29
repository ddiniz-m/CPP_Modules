#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure& operator=(const Cure &copy_a);
		Cure(const Cure &copy);

		void use(ICharacter& target);
		virtual AMateria* clone() const;

};

#endif