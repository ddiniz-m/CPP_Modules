
#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weaponREF;

	public:
		HumanA(std::string name, Weapon &weaponREF);
		~HumanA();
		void	attack();
		void	setWeapon(Weapon weapon);
};

#endif