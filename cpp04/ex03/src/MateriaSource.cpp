
#include "../inc/MateriaSource.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
MateriaSource::MateriaSource()
{
	std::cout << GREEN << "MateriaSource Default Constructor Called" << NC << std::endl;
	for (int i =0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy_a)
{
	std::cout << GREEN << "MateriaSource Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << GREEN << "MateriaSource Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	MateriaSource::learnMateria(AMateria* m)
{
	static int i = 0;
	this->materia[i] = m;
	std::cout << "materia[" << i << "] learned type " << m->getType() << ": " << this->materia[i]->getType() << std::endl;
	i++;
	if (i == 3)
		i = 0;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && type.compare(this->materia[i]->getType()) == 0)
		{
			std::cout << "Type: " << type << " | this->materia[i]: " << this->materia[i]->getType()<< std::endl;
			return (this->materia[i]->clone());
		}
	}
	std::cout << "Unkown type!" << std::endl;
	return (NULL);
}