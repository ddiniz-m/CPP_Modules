
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

class Animal
{
	private:
		std::string	type;
	public:
		Animal();
		~Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal &copy_a);

		std::string	getType(void) const;
		void		makeSound(void) const;
		void		setType(std::string name);

};

#endif