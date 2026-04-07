#include "ScalarConverter.hpp"
#include <bits/stdc++.h>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	std::cout << "Assigment operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

Type detectType(std::string s, int len)
{
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff")
		return SPECIAL;

	if (len == 1 && !(s[0] >= '0' && s[0] <= '9'))
		return CHAR;

	int	i = 0;
	if (s[0])
	{
		if (s[0] == '+' || s[0] == '-')
			i = 1;
		while (i < len && std::isdigit(s[i]))
			i++;
		if (len == i)
			return INT;
	}

	int	dot = 0;
	int num = 0;
	i = 0;
	if (s[0])
	{
		if (s[0] == '+' || s[0] == '-')
			i = 1;
		while (i < len && std::isdigit(s[i]))
		{
			i++;
			num = 1;
		}
		if (i < len && num == 1 && s[i] == '.')
		{
			i++;
			dot = 1;
		}
		while (i < len && std::isdigit(s[i]))
			i++;
		if (i < len && s[i] == 'f' && i == (len - 1) && dot == 1)
			return FLOAT;
		if (i == len && dot == 1)
			return DOUBLE;
	}

	return ERROR;
}

void ScalarConverter::convert(std::string s)
{
	int		len = s.length();
	int		i;
	//double	d;


	if (len < 1)
	{
		std::cerr << "Input is missing" << std::endl;
		return ;
	}

	Type	t = detectType(s, len);




	//else
	//{
	//	std::cout << "char: Non displayable" << std::endl;
	//	char	c[2];
	//	c[1] = '\0';
	//	c[0] = s[0];
	//	i = std::atoi(c);
	//	std::cout << "int: " << i << std::endl;
	//}
	
	
	
}
