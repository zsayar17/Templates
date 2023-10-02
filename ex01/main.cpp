#include "Iter.hpp"

int main()
{
	const int array_len = 5;
	std::string strings[array_len];
	int ints[array_len];
	double doubles[array_len];

	for (int i = 0; i < array_len; i++)
	{
		std::stringstream stream;

		stream << i + 1;
		strings[i] = "deneme_";
		strings[i] += stream.str();
	}
	for (int i = 0; i < array_len; i++)
	{
		ints[i] = i + 1;
	}
	for (int i = 0; i < array_len; i++)
	{
		doubles[i] = i + 0.5;
	}
	iter(strings, array_len, printValue);
	iter(ints, array_len, printValue);
	iter(doubles, array_len, printValue);
}
