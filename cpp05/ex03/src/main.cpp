
#include "../inc/Form.hpp"
#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

void	deleteForm(Form **form)
{
	for (int i = 0; i < 4; i++)
		delete(form[i]);
}

int	main(void)
{
	Bureaucrat	Boss(1, "Boss-man");
	Intern		randomIntern;
	Form		*form[4];
	std::cout << "\n";

	form[0] = randomIntern.makeForm("shrubbery request", "Home");
	form[1] = randomIntern.makeForm("robotomy creation", "lagann");
	form[2] = randomIntern.makeForm("presidential pardon", "Captain");
	form[3] = randomIntern.makeForm("chloroform", "target");

	for (int i = 0; i < 4; i++)
	{
		if (!form[i])
			break ;
		Boss.signForm(*form[i]);
	}

	std::cout << "\n";

	for (int i = 0; i < 4; i++)
	{
		if (!form[i])
			break ;
		Boss.executeForm(*form[i]);
	}

	deleteForm(form);
	return (0);
}