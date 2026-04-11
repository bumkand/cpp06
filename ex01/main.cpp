#include "Serializer.hpp"

int	main()
{
	Data	ptr;

	ptr.i = 28;
	ptr.s = "Jakub";

	uintptr_t raw = Serializer::serialize(&ptr);
	std::cout << "The value of raw is " << raw << std::endl;
	std::cout << "The value of &ptr is " << &ptr << std::endl;

	Data*	newptr = Serializer::deserialize(raw);
	std::cout << "The value of newptr is " << newptr << std::endl;

	if (newptr == &ptr)
		std::cout << "Adresses are the same" << std::endl;
	else
		std::cout << "Adresses are not the same" << std::endl;

	return 0;
}