
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
		ScavTrap st;
		FragTrap ft;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap& operator=(const DiamondTrap &copy_a);

		void	whoAmI(void);
		void	attack(const std::string& target);
};

#endif