#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];
	public:
		MateriaSource();
		virtual ~MateriaSource();
		MateriaSource& operator=(const MateriaSource &copy_a);
		MateriaSource(const MateriaSource &copy);

		virtual void		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif