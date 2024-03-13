#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "Form.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class RobotomyRequestForm : public Form
{
	private:
		const std::string	target;
		const std::string	name;
		bool				sign;
		const int			signGrade;
		const int			execGrade;
		
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm &copy_a);
		RobotomyRequestForm(const RobotomyRequestForm &copy);

		std::string		getName(void) const;
		bool			getSign(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		std::string		getTarget(void) const;

		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream& os, RobotomyRequestForm &Robo);

#endif

