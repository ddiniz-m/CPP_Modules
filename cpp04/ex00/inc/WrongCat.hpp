
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat& operator=(const WrongCat &copy_a);

		void	makeSound(void);
};

#endif