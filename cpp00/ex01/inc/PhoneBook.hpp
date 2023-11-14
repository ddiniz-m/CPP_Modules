
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	void	search_book(void);
	void	add_contact(int index);
	std::string	truncate(std::string str);

	private:
		Contact	Contacts[8];
	
};

#endif
