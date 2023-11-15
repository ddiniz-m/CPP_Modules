
#ifndef ZOMBIE_CPP
# define ZOMBIE_CPP

# include <iostream>
# include <string>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define NC "\033[0m"

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		~Zombie();
		void		announce(void);
		Zombie		*newZombie(std::string name);
		void		randomChump(std::string name);
};

#endif