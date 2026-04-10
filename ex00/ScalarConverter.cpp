#include "ScalarConverter.hpp"

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

void ScalarConverter::convert(std::string s)
{
	int		len = s.length();
	double	d;


	if (len < 1)
	{
		std::cerr << "Input is missing" << std::endl;
		return ;
	}

	Type	t = detectType(s, len);

	d = parseValue(s, t);

	if (t == ERROR)
	{
		std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;
		return ;
	}
	charConvert(d);
	intConvert(d);
	floatConvert(d);
	doubleConvert(d);
}
