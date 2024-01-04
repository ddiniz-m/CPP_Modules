
#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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