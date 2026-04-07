#include "ScalarConverter.hpp"

int	main(int arc, char *arv[])
{
	if (arc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(arv[1]);
	return 0;
}