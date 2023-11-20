
#include "../inc/Harl.hpp"

int	main(int ac, char **av)
{
	Harl	object;
	if (ac != 2)
	{
		std::cout << "Incorrect number of arguments!" << std::endl;
		return (1);
	}

	std::string str = std::string (av[1]);
	enum	levels	{DEBUG, INFO, WARNING, ERROR};
	levels	signal;

	if (str.compare("DEBUG") == 0)
		signal = DEBUG;
	if (str.compare("INFO") == 0)
		signal = INFO;
	if (str.compare("WARNING") == 0)
		signal = WARNING;
	if (str.compare("ERROR") == 0)
		signal = ERROR;

	switch (signal)
	{
		case 0:
		{
			object.complain("DEBUG");
			object.complain("INFO");
			object.complain("WARNING");
			object.complain("ERROR");
			break;
		}
		case 1:
		{
			object.complain("INFO");
			object.complain("WARNING");
			object.complain("ERROR");
			break;
		}
		case 2:
		{
			object.complain("WARNING");
			object.complain("ERROR");
			break;
		}
		case 3:
		{
			object.complain("ERROR");
			break;
		}
		default:
		{
			std::cout << "Not a valid signal!" << std::endl;
			break;
		}
	}
}