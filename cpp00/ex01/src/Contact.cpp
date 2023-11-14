#include <iostream>
#include "../inc/Contact.hpp"

std::string	Contact::input_field(std::string str)
{
	std::string field;
	while (1)
	{
		std::cout << "Enter " << str << ":" << std::endl;
		if (!getline(std::cin, field))
			break ;
		if (field.empty())
		{
			std::cout << "Field must nor be empty" << std::endl;
			continue ;
		}
		return (field);
	}
	return (field);
}

std::string Contact::get_field(int i)
{
	if (i == 1)
		return (FirstName);
	if (i == 2)
		return (LastName);
	if (i == 3)
		return (Nickname);
	if (i == 4)
		return (PhoneNumber);
	if (i == 5)
		return (DarkSecret);
	return (0);
}

Contact Contact::add()
{
	Contact contact;

	contact.FirstName = input_field("First Name");
	contact.LastName = input_field("Last Name");
	contact.Nickname = input_field("Nickname");
	contact.PhoneNumber = input_field("Phone Number");
	contact.DarkSecret = input_field("Darkest Secret");
	return (contact);
}