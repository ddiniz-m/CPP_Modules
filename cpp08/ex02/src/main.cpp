#include "../inc/MutantStack.hpp"

int	main(void)
{
	std::cout << YELLOW << "MUTANT_STACK:\n" << NC;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "FRONT: " <<mstack.top() << std::endl;
		mstack.pop();
		std::cout << "SIZE: "<< mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	
		std::stack<int> s(mstack);
		int	i;
		std::cout << MAGENTA << "\nSTD::STACK:\n" << NC;
		while (!s.empty())
		{
			i = s.top();
			std::cout << i << "\n";
			s.pop();
		}
	}
	std::cout << CYAN << "\nSTD::LIST:\n" << NC;
	{
		std::list<int>	lst;

		lst.push_back(5);
		lst.push_back(17);
		std::cout << "FRONT: " << lst.front() << std::endl;
		lst.pop_front();
		std::cout << "SIZE: " << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);

		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << CYAN << "\nCOPY_LIST:\n" << NC;
	
		std::list<int> l(lst);
		std::list<int>::iterator ibeg = l.begin();
		std::list<int>::iterator iend = l.end();
		++ibeg;
		--ibeg;
		while (ibeg != iend)
		{
			std::cout << *ibeg << std::endl;
			++ibeg;
		}
		return 0;
	}
}