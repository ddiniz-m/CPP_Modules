
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain& operator=(const Brain &copy_a);

		void	setIdeas(char c);
		void	printIdea(std::string Owner);
};

#endif