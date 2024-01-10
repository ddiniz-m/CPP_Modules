
#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy_a);

		void	makeSound(void);

};

#endif