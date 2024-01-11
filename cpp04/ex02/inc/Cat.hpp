
#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &copy_a);

		void	makeSound(void) const;
		Brain *getBrain(void);

};

#endif