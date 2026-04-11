#include "Functions.hpp"

int	main()
{
	srand(time(NULL));

	Base* base = generate();

	identify(base);

	identify(*base);

	delete base;

	return 0;
}