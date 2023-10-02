#include "Array.hpp"


int main()
{
	std::cout << "~~~~INT TEST~~~~\n";
	{
		const int size = 5;
		Array<int> array(size);

		for (int i = 0; i < size; i++) array[i] = i;
		for (int i = 0; i < size; i++) std::cout << array[i] << std::endl;

		try {
			array[size];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try {
			array[-1];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "array size: " << array.size() << std::endl;
	}
	std::cout << "\n~~~~CHAR TEST~~~~\n";
	{
		const int size = 5;
		Array<char> array(size);

		for (int i = 0; i < size; i++) array[i] = 'a' + i;
		for (int i = 0; i < size; i++) std::cout << array[i] << std::endl;

		try {
			array[size];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try {
			array[-1];
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "array size: " << array.size() << std::endl;
	}
	std::cout << "\n~~~~COPY ASSIGNMENT TEST~~~~\n";
	{
		Array<int> array(10);
		Array<int> array1;

		std::cout << "array size: " << array.size() << std::endl;
		std::cout << "array size: " << array1.size() << std::endl;

		std::cout << "array variables: ";
		for (size_t i = 0; i < array.size(); i++) std::cout << array[i] << " ";
		std::cout << std::endl;

		std::cout << "array1 variables: ";
		for (size_t i = 0; i < array1.size(); i++) std::cout << array1[i] << " ";
		std::cout << std::endl;

		for (size_t i = 0; i < array.size(); i++) array[i] = i;

		std::cout << "array variables: ";
		for (size_t i = 0; i < array.size(); i++) std::cout << array[i] << " ";
		std::cout << std::endl;

		std::cout << "array1 variables: ";
		for (size_t i = 0; i < array1.size(); i++) std::cout << array1[i] << " ";
		std::cout << std::endl;

		array1 = array;

		std::cout << "array size: " << array.size() << std::endl;
		std::cout << "array size: " << array1.size() << std::endl;

		std::cout << "array variables: ";
		for (size_t i = 0; i < array.size(); i++) std::cout << array[i] << " ";
		std::cout << std::endl;

		std::cout << "array1 variables: ";
		for (size_t i = 0; i < array1.size(); i++) std::cout << array1[i] << " ";
		std::cout << std::endl;
	}

	system("leaks templates");

}
