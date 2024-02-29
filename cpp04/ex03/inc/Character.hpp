#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria *inventory[4];
		std::string name;
	public:
		Character();
		Character(std::string name);
		~Character();
		Character& operator=(const Character &copy_a);
		Character(const Character &copy);

		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif