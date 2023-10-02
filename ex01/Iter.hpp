#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <iostream>
#include <sstream>

template <typename T>
void iter(T* adress, size_t size, void (*f_ptr)(T)) {
	for (size_t i = 0; i < size; i++) f_ptr(adress[i]);
}

template <typename T>
void printValue(T t)
{
	std::cout << t << std::endl;
}

#endif
