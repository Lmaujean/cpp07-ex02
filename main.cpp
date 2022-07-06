
#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

int main(int, char**)
{
	Array<int>	numbers(MAX_VAL);
	int*		mirror = new int[MAX_VAL];

	srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++)	// Test pour comparer int[750] et Array[750]
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)	// Verification que toutes les valeurs sont egales
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
		numbers[MAX_VAL] = 0;	// 750 : le max est 749
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;
	return 0;
}