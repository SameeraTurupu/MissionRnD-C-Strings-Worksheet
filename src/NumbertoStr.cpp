/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <stdlib.h>
int ipow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}
int intToStr(int integerPart, char *str, int afterdecimal)
{
	int index = 0, index1 = 0;
	if (integerPart < 0)
		index1 = 1;
	if (integerPart < 0) {
		str[index++] = '-';
		integerPart = abs(integerPart);
	}
	while (integerPart)
	{
		str[index++] = (integerPart % 10) + '0';
		integerPart /= 10;
	}
	while (index < afterdecimal)
		str[index++] = '0';
	int index2 = index - 1, temp;
	while (index1<index2)
	{
		temp = str[index1];
		str[index1] = str[index2];
		str[index2] = temp;
		index1++; index2--;
	}
	str[index] = '\0';
	return index;
}
void number_to_str(float number, char *str, int afterdecimal){
	int integerPart = (int)number;
	float floatPart = number - (float)integerPart;
	int integerToString = intToStr(integerPart, str, 0);
	if (afterdecimal != 0)
	{
		str[integerToString] = '.';
		floatPart = floatPart * ipow(10, afterdecimal);
		intToStr(abs((int)floatPart), str + integerToString + 1, afterdecimal);
	}
}
