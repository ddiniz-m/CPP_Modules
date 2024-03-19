
#include "../inc/Serializer.hpp"

// ---------------------- Orthodox Canonical Form -----------------------------
Serializer::Serializer()
{
	std::cout << GREEN << "Serializer Default Constructor Called" << NC << std::endl;
}

Serializer& Serializer::operator=(const Serializer &copy_a)
{
	std::cout << GREEN << "Serializer Copy Assignment Operator Called" << NC << std::endl;
	(void)copy_a;
	return (*this);
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << GREEN << "Serializer Copy Constructor Called" << NC << std::endl;
	*this = copy;
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer Destructor Called" << NC << std::endl;
}
// ---------------------- Orthodox Canonical Form -----------------------------

uintptr_t	Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}