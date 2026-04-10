#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
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

Type detectType(std::string s, int len);
double parseValue(std::string s, Type t);
void charConvert(double d);
void intConvert(double d);
void floatConvert(double d);
void doubleConvert(double d);


#endif