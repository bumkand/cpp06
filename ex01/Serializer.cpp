#include "Serializer.hpp"

Serializer::Serializer()
{
	//std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	(void) other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	//std::cout << "Assigment operator called" << std::endl;
	(void) other;
	return *this;
}

Serializer::~Serializer()
{
	//std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{

}
Data* Serializer::deserialize(uintptr_t raw)
{

}