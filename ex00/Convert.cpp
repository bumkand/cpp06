#include "ScalarConverter.hpp"

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

double parseValue(std::string s, Type t)
{
	double	d = 0;

	if (t == CHAR)
	{
		d = s[0];
		return d;
	}
	if (t == INT || t == DOUBLE)
	{
		d = std::strtod(s.c_str(), NULL);
		return d;
	}
	if (t == FLOAT)
	{
		s.erase(s.length() - 1);
		d = std::strtod(s.c_str(), NULL);
		return d;
	}
	if (t == SPECIAL)
	{
		if (s == "nan" || s == "nanf")
			return std::numeric_limits<double>::quiet_NaN();

		if (s == "+inf" || s == "+inff")
			return std::numeric_limits<double>::infinity();

		if (s == "-inf" || s == "-inff")
			return -std::numeric_limits<double>::infinity();
	}

	return d;
}

void charConvert(double d)
{
	if (d != d || d == std::numeric_limits<double>::infinity()
		|| d == -std::numeric_limits<double>::infinity()
		|| d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((d >= 0 && d < 32) || d == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		std::cout << "char: '" << c << "'" << std::endl;
	}	
}

void intConvert(double d)
{
	
	if (d != d || d == std::numeric_limits<double>::infinity()
		|| d == -std::numeric_limits<double>::infinity())
		std::cout << "int: impossible" << std::endl;
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
}

void floatConvert(double d)
{
	if (d != d)
		std::cout << "float: nanf" << std::endl;
	else if (d == std::numeric_limits<double>::infinity()
			|| d == -std::numeric_limits<double>::infinity())
	{
		if (d > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	else if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(d);
		if ((f - floor(f)) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
}

void doubleConvert(double d)
{	
	if (d != d)
		std::cout << "double: nan" << std::endl;
	else if (d == std::numeric_limits<double>::infinity()
			|| d == -std::numeric_limits<double>::infinity())
	{
		if (d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	else
	{
		double f = static_cast<double>(d);
		if ((f - floor(f)) == 0)
			std::cout << "double: " << f << ".0" << std::endl;
		else
			std::cout << "double: " << f << std::endl;
	}
	
}
