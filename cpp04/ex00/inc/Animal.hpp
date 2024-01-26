
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy_a);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		void			setType(std::string name);

};

#endif