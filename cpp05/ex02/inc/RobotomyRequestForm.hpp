#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

#define NC "\033[0m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"

class RobotomyRequestForm : public AForm
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

		RobotomyRequestForm(std::string target);
		void	execute(Bureaucrat const & executor) const;

};

#endif

