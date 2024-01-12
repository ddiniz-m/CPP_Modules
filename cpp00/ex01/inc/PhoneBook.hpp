
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	Contacts[8];

	public:
		PhoneBook();
		~PhoneBook();
		void	search_book(void);
		void	add_contact(int index);
		std::string	truncate(std::string str);

	
};

#endif
