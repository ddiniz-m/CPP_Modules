
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
	for (int i =0; i < 4; i++)
	{
		if (this->materia[i])
			this->materia[i] = copy_a.materia[i];
		else
			this->materia[i] = NULL;
	}
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
	for (int i =0; i < 4; i++)
	{
		if (this->materia[i])
			delete(this->materia[i]);
		this->materia[i] = NULL;
	}
}
// ---------------------- Orthodox Canonical Form -----------------------------

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i =0; i < 4; i++)
	{
		if (!this->materia[i])
		{
			this->materia[i] = m;
			std::cout << "materia[" << i << "] learned type " << m->getType() << ": ";
			std::cout << this->materia[i]->getType() << std::endl;
			return ;
		}
	}
	delete m;
	
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] && type.compare(this->materia[i]->getType()) == 0)
			return (this->materia[i]->clone());
	}

	return (0);
}