
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

class Contact
{
	public:
		std::string	get_field(int i);
		std::string	input_field(std::string str);
		Contact add(void);

	private:
		std::string PhoneNumber;
		std::string LastName;
		std::string Nickname;
		std::string FirstName;
		std::string DarkSecret;
};

#endif