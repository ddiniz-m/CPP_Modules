
#include "../inc/WrongCat.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

int main()
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	delete(i);
	delete(j);

	Animal *arr[10];
	for (int k = 0; k < 10; k++)
	{
		if (k < 5)
			arr[k] = new Dog;
		else
			arr[k] = new Cat;
	}

	std::cout << std::endl;

	Dog _Dog;
	Brain *_Brain;
	_Brain = _Dog.getBrain();
	_Brain->setIdeas("MAIN BRAIN");
	std::cout << "Brain:" << std::endl;
	_Brain->printIdea();

	Dog CopyDog = _Dog;
	Brain *CopyBrain;
	CopyBrain = CopyDog.getBrain();
	std::cout << "Copy Brain:" << std::endl;
	CopyBrain->printIdea();

	_Brain->setIdeas("CHANGED BRAIN");
	std::cout << "Brain:" << std::endl;
	_Brain->printIdea();

	CopyBrain = CopyDog.getBrain();
	std::cout << "Copy Brain:" << std::endl;
	CopyBrain->printIdea();

	std::cout << std::endl;
	for (int k = 0; k < 10; k++)
		delete(arr[k]);
	return 0;
}
