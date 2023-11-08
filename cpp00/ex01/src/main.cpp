#include <iostream>
#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"

int main(void)
{
	int			i;
	std::string	line;
	PhoneBook	phonebook;

	i = 0;
	while (1)
	{
		if (i == 8)
			i = 0;
		std::cout << "Please enter one of the following commands: ADD, SEARCH, EXIT" << std::endl;
		if (!getline(std::cin, line))
			return (0);
		if ((line.compare("ADD") != 0 && line.compare("SEARCH") != 0 && line.compare("EXIT") != 0))
			std::cout << "Not a valid command!" << std::endl;
		else if (line.compare("ADD") == 0)
			phonebook.Contacts[i++] = add_contact();
		else if (line.compare("SEARCH") == 0)
			search_book(phonebook);
		else if (line.compare("EXIT") == 0)
			return (0);
	}
}