#include <string>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook Object Created" << std::endl;
}

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	print_field(std::string str, std::string field)
{
	while (1)
	{
		std::cout << "Enter" << str << ":" << std::endl;
		if (!getline(std::cin, field))
			break ;
		if (field.empty())
		{
			std::cout << "Field must nor be empty" << std::endl;
			continue ;
		}
		break ;
	}
}

Contact	add_contact(void)
{
	Contact contact;

	print_field("First Name", contact.FirstName);
	print_field("Last Name", contact.LastName);
	print_field("Nickname", contact.Nickname);
	print_field("Phone Number", contact.PhoneNumber);
	print_field("Darkest Secret", contact.DarkSecret);
	return (contact);
}

void	search_book(PhoneBook phonebook)
{
	int			i;
	std::string	line;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw (10) << i << "|";
		std::cout << std::setw (10) << truncate(phonebook.Contacts[i].FirstName) << "|";
		std::cout << std::setw (10) << truncate(phonebook.Contacts[i].LastName) << "|";
		std::cout << std::setw (10) << truncate(phonebook.Contacts[i].Nickname) << "|";
		std::cout << std::setw (10) << truncate(phonebook.Contacts[i].PhoneNumber) << "|";
		std::cout << std::setw (10) << truncate(phonebook.Contacts[i].DarkSecret) << "|";
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
			std::cout << "First Name:	" << phonebook.Contacts[i].FirstName << std::endl;
			std::cout << "Last Name:	" << phonebook.Contacts[i].FirstName << std::endl;
			std::cout << "Nickname:	" << phonebook.Contacts[i].FirstName << std::endl;
			std::cout << "Phone Number:	" << phonebook.Contacts[i].FirstName << std::endl;
			std::cout << "Darkest Secret:	" << phonebook.Contacts[i].FirstName << std::endl;
		}
		return ;
	}
} 
