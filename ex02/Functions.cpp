#include "Functions.hpp"

Base* generate(void)
{
	int num1 = (rand() % 10) + 1;
	int	num2 = (rand() % 10) + 1;
	int num3 = (rand() % 10) + 1;

	if (num1 > num2 && num1 > num3)
	{
		Base* b = new A();
		return b;
	}
	else if (num2 > num1 && num2 > num3)
	{
		Base* b = new B();
		return b;
	}
	else
	{
		Base* b = new C();
		return b;
	}	
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	else
		std::cout << "Bad Cast" << std::endl;
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
		}
		
	}
	
}