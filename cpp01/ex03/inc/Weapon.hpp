
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define NC "\033[0m"

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string	&getType(void);
		void				setType(std::string type);
};

#endif