#include <iostream>
#include <string>
#include <cstdlib>
#include "../inc/Array.hpp"


#define MAX_VAL 10
int main(int, char**)
{
	
	{
		Array<std::string>arr(10);
		for (int i = 0; i < arr.size(); i++)
			arr[i] = 'a' + (rand() % 10);

		std::cout << YELLOW;
		arr.myPrint();
		std::cout << NC << "\n";
		
		Array<std::string>copy_a = arr;
		Array<std::string>copy(arr);
		
		std::cout << NC << "\n" << MAGENTA;
		copy.myPrint();
		std::cout << NC << "\n" << YELLOW;
		copy_a.myPrint();
		std::cout << NC << "\n";

		try
		{
			arr[-1] = 123;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			arr[1000] = 123;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

	}
	{
		Array<int>numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			std::cout << YELLOW;
			numbers.myPrint();
			std::cout << NC << "\n";
		
			Array<int>tmp = numbers;
			Array<int>test(tmp);
	
			std::cout << MAGENTA;
			tmp.myPrint();
			std::cout << NC << "\n" << YELLOW;
			test.myPrint();
			std::cout << NC << "\n";
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;//
		return 0;
	}
}