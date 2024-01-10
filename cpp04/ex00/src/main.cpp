
#include "../inc/WrongCat.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete(meta);
	delete(i);
	delete(j);

	std::cout << std::endl;

	Dog Terrier;
	Animal *k = &Terrier;
	std::cout << "Terrier is of type: " << k->getType() << std::endl;
	std::cout << "Terrier made the sound: ";
	k->makeSound();

	std::cout << std::endl << "WRONG ANIMAL:" << std::endl;

	const WrongAnimal *OrangeCat = new WrongCat();
	std::cout << "OrangeCat is of type: " << OrangeCat->getType() << std::endl;
	OrangeCat->makeSound();

	WrongCat SiameseCat;
	WrongAnimal *f = &SiameseCat;
	std::cout << "SiameseCat is of type: " << f->getType() << std::endl;
	f->makeSound();

	delete(OrangeCat);

	return 0;
}
