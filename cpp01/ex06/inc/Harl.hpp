
#ifndef		HARL_HPP
# define	HARL_HPP

#include <iostream>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define NC "\033[0m"

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};

#endif