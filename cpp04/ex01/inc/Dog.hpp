
#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &copy_a);

		void	makeSound(void) const;
		Brain *getBrain(void);
};

#endif