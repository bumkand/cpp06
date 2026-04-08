#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits>
#include <cmath>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(std::string s);
};

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	ERROR
};

#endif