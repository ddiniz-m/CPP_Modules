
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string name;
		using FragTrap::hp;
		using ScavTrap::energy;
		using FragTrap::atk;
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