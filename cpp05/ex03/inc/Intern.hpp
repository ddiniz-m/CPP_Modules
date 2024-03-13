#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class Form;

class Intern
{
	private:
		
	public:
		Intern();
		~Intern();
		Intern& operator=(const Intern &copy_a);
		Intern(const Intern &copy);

		Form	*returnPres(std::string target);
		Form	*returnShrub(std::string target);
		Form	*returnRobot(std::string target);
		Form	*makeForm(std::string name, std::string target);
};

#endif

