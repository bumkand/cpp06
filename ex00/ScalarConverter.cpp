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
	long double	d = 0;

	if (t == CHAR)
	{
		d = s[0];
		return d;
	}
	if (t == INT)
	{
		long long int i = atol(s.c_str());
		d = static_cast<long double>(i);
		return d;
	}
	if (t == FLOAT)
	{
		s.erase(s.length() - 1);
		d = std::atof(s.c_str());
		return d;
	}
	if (t == DOUBLE)
	{
		d = std::atof(s.c_str());
		return d;
	}
	if (t == SPECIAL)
	{
		if (s == "nan")
			return std::numeric_limits<double>::quiet_NaN();

		if (s == "nanf")
			return std::numeric_limits<double>::quiet_NaN();
		if (s == "+inf")
			return std::numeric_limits<double>::infinity();

		if (s == "-inf")
			return -std::numeric_limits<double>::infinity();

		if (s == "+inff")
			return std::numeric_limits<double>::infinity();

		if (s == "-inff")
			return -std::numeric_limits<double>::infinity();
	}

	return d;
}

void charConvert(long double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if ((d >= 0 && d < 32) || d == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		std::cout << "char: " << c << std::endl;
	}	
}

void intConvert(long double d)
{
	
	if (std::isnan(d) || std::isinf(d))
		std::cout << "int: impossible" << std::endl;
	else if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
	{
		int i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
}

void floatConvert(long double d)
{
	if (std::isnan(d))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(d))
	{
		if (d > 0)
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
	//else if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
	//	std::cout << "float: impossible" << std::endl;
	else
	{
		float f = static_cast<float>(d);
		if ((f - floor(f)) == 0)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
}

void doubleConvert(long double d)
{	
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
	{
		if (d > 0)
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
	//else if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
	//	std::cout << "double: impossible" << std::endl;
	else
	{
		double f = static_cast<double>(d);
		if ((f - floor(f)) == 0)
			std::cout << "double: " << f << ".0" << std::endl;
		else
			std::cout << "double: " << f << std::endl;
	}
	
}

void ScalarConverter::convert(std::string s)
{
	int		len = s.length();
	long double	d;


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
