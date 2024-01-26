#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const &type);
		~AMateria();
		AMateria& operator=(const AMateria &copy_a);
		AMateria(const AMateria &copy);

		std::string const &getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		void	setType(std::string const &type);
};

#endif