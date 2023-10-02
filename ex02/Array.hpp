#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

#include <iostream>
#include <sstream>

template <typename T>
class Array
{
	private:
		T* t_ptr;
		size_t ptr_size;

		class OutOfBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NullValue : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
		Array();
		~Array();
		Array(size_t ptr_size);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](size_t index);

		size_t size() const;
};

template <typename T>
Array<T>::Array() {
	t_ptr = NULL;
	ptr_size = 0;
}

template <typename T>
Array<T>::Array(size_t ptr_size) {
	t_ptr = new T[ptr_size];
	this->ptr_size = ptr_size;
}

template <typename T>
Array<T>::Array(const Array<T>& other) {
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this == &other) return (*this);
	if (this->t_ptr) delete[] t_ptr;
	this->ptr_size = other.ptr_size;

	if (!other.t_ptr) {
		t_ptr = NULL;
		return (*this);
	}
	t_ptr = new T[ptr_size];
	for (size_t i = 0; i < ptr_size; i++) t_ptr[i] = other.t_ptr[i];
	return (*this);
}

template <typename T>
Array<T>::~Array<T>() {
	if (this->t_ptr) delete[] this->t_ptr;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (!t_ptr) throw(NullValue());
	else if (index >= ptr_size || ptr_size < 0) throw(OutOfBounds());
	return (t_ptr[index]);
}

template <typename T>
size_t Array<T>::size() const {
	return (ptr_size);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw() {
	return ("Out of bounds");
}

template <typename T>
const char* Array<T>::NullValue::what() const throw() {
	return ("Null Value");
}

#endif
