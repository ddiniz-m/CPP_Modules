
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		virtual ~AAnimal();
		AAnimal& operator=(const AAnimal &copy_a);
		AAnimal(const AAnimal &copy);

		std::string	getType(void) const;
		virtual void		makeSound(void) const = 0;
		void		setType(std::string name);

};

#endif

