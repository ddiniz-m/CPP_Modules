
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap& operator=(const ScavTrap &copy_a);

		void	guardGate(void);
		void	attack(const std::string& target);
};

#endif