
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap& operator=(const FragTrap &copy_a);

		void	highFivesGuys(void);
		void	attack(const std::string& target);
};

#endif