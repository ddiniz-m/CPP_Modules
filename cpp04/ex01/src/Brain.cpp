
#include "../inc/Brain.hpp"
#include <string>

// ---------------------- Orthodox Canonical Form -----------------------------
Brain::Brain()
{
	std::cout << GREEN << "Brain Default Constructor Called" << NC << std::endl;
}

Brain& Brain::operator=(const Brain &copy_a)
{
	std::cout << GREEN << "Brain Copy Assignment Operator Called" << NC << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy_a.ideas[i];
	return (*this);
}

Brain::Brain(const Brain &copy)
{
	std::cout << GREEN << "Brain Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << RED << "Brain Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

	void	Brain::setIdeas(std::string str)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = str;
	}

	void	Brain::printIdea(void)
	{
		std::cout << "Idea: " << this->ideas[50] << std::endl;
	}