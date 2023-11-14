#include <iostream>
#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "\033[0;32mPhoneBook Object Created\033[0m" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\033[0;31mPhoneBook Object Destroyed\033[0m" << std::endl;
}

std::string	PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::add_contact(int index)
{
	Contact contact;
	Contacts[index] = contact.add();
}

void	PhoneBook::search_book(void)
{
	int			i;
	std::string	line;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw (10) << i << "|";
		std::cout << std::setw (10) << truncate(Contacts[i].get_field(1)) << "|";
		std::cout << std::setw (10) << truncate(Contacts[i].get_field(2)) << "|";
		std::cout << std::setw (10) << truncate(Contacts[i].get_field(3)) << "|";
		std::cout << std::setw (10) << truncate(Contacts[i].get_field(4)) << "|";
		std::cout << std::setw (10) << truncate(Contacts[i].get_field(5)) << "|";
		std::cout << std::endl;
	}
	while (1)
	{
		i = 0;
		std::cout << "Enter Index" << std::endl;
		if (!getline(std::cin, line))
			return ;
		i = atoi(line.c_str());
		if (i < 0 || i > 7)
		{
			std::cout << "Index Error" << std::endl;
			continue ;
		}
		else
		{
			std::cout << "First Name:	" << Contacts[i].get_field(1) << std::endl;
			std::cout << "Last Name:	" << Contacts[i].get_field(2) << std::endl;
			std::cout << "Nickname:	" << Contacts[i].get_field(3) << std::endl;
			std::cout << "Phone Number:	" << Contacts[i].get_field(4) << std::endl;
			std::cout << "Darkest Secret:	" << Contacts[i].get_field(5) << std::endl;
		}
		return ;
	}
} 