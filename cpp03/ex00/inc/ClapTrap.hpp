#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define RED "\033[0;31m"
# define NC "\033[0m"

class ClapTrap
{
	private:
		std::string		name;
		int	hp;
		int	energy;
		int	atk;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap& operator=(const ClapTrap &copy_a);

		int check(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string	getName(void);
		int			getAttack(void);
		int			getHp(void);
		int			getEnergy(void);

		void		setAttack(unsigned int amount);
		void		setEnergy(unsigned int amount);

};

#endif