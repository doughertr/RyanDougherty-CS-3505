#include "huge_integer.h"
#include <iostream>
using namespace std;
huge_integer::huge_integer(const string & s)
{
	//check to see if the string contains ONLY non-negative integers
	if(!(s.find_first_not_of("0123456789") == string::npos))
		val = "0"; //assign default value of 0 if the passed string is not a non-negative integer
	else
		val = s;
}
huge_integer::huge_integer()
{
	val = "0";
}
huge_integer::huge_integer(const huge_integer & other)
{	
	val = other.val; 
}
string huge_integer::get_value() const
{
	return val;
}
huge_integer& huge_integer::operator=(const huge_integer right)
{
	this->val = right.val;
	return *this;
}
huge_integer huge_integer::operator+(const huge_integer right) const
{
	string result = "";
	string leftNumString = this->get_value();
	string rightNumString = right.get_value();
	
	//get lengths of left and right strings
	int leftPos = leftNumString.length() - 1;
	int rightPos = rightNumString.length() - 1;
	int carry = 0;

	while(leftPos >= 0 || rightPos >= 0 || carry > 0)
	{
		//get the left and right digit of the strings if they exist
		//if not, then set them to 0.
		//subtracting the char 0 from the returned character will yeild
		//the integer value of the character.
		int leftDigit = leftPos >= 0 ? leftNumString[leftPos--] - '0' : 0;
		int rightDigit = rightPos >= 0 ? rightNumString[rightPos--] - '0' : 0;		
		//add the two digits and the carried value together
		int sum = leftDigit + rightDigit + carry;
		//the carried value will be the the number in the 10's digit.
		//the sum integer will be the value in the 1's digit. 
		carry = sum / 10;
		sum = sum % 10;
		//insert the sum into the final result
		result.insert(0, 1, (char)(sum + '0'));
	}
	
	//delete all leading zeros
	//while(result.length() > 1 && result[0] == '0')
		//result.erase(0, 1);
	//create 
	huge_integer returnedVal(result);
	return returnedVal;
}
huge_integer huge_integer::operator-(const huge_integer right) const
{
	string result = "";
	string leftNumString = this->get_value();
	string rightNumString = right.get_value();

	//get lengths of left and right strings
	int leftPos = leftNumString.length() - 1;
	int rightPos = rightNumString.length() - 1;

	while(leftPos >= 0 || rightPos >= 0)
	{
		//get the left and right digit of the strings if they exist
		//if not, then set them to 0.
		//subtracting the char 0 from the returned character will yeild
		//the integer value of the character.
	
		int leftDigit = leftPos >= 0 ? leftNumString[leftPos] - '0' : 0;
		int rightDigit = rightPos >= 0 ? rightNumString[rightPos] - '0' : 0;
	
		if(leftDigit < rightDigit)
		{
			if(!borrow(leftNumString, rightNumString, leftPos, rightPos))
			{
				huge_integer defaultInteger;
				return defaultInteger;
			}	
			leftDigit = leftPos >= 0 ? leftNumString[leftPos] - '0' : 0;
			rightDigit = rightPos >= 0 ? rightNumString[rightPos] - '0' : 0;
		}
		leftPos--;
		rightPos--;
		
		//subtract the two digits together
		int difference = leftDigit - rightDigit;
		result.insert(0, 1, (char)(difference + '0'));
	}
	huge_integer returnedVal(result);
	return returnedVal;
}
huge_integer huge_integer::operator*(const huge_integer right) const
{
	string result = "";
	string leftNumString = this->get_value();
	string rightNumString = right.get_value();

	int rightPos = 0;
	while(rightPos < (int)rightNumString.length())
	{
		//multiply the number by 10
		result.append("0");
		int rightDigit = rightNumString[rightPos++] - '0';
		for(int i = 0; i < rightDigit; i++)
		{
			//add the right to the left the amount of the right
			//digit
			result = (*this + huge_integer(result)).get_value(); 
		}
	}
	return huge_integer(result);
	
}
huge_integer huge_integer::operator/(const huge_integer right) const
{
	string result = "";
	string rightNumString = this->get_value();
	string leftNumString = this->get_value();
	//check for divide by zero division
	if(rightNumString == "0" || leftNumString == "0")
	{
		return huge_integer("0");
	}

	int leftPos = 0, rightPos = 0;
	int leftLength = leftNumString.length(), rightLength = rightNumString.length();
	int leftDigit = leftNumString[leftPos] - '0';
	int rightDigit = rightNumString[rightPos] - '0';
	
	while(leftPos < (int)leftNumString.length())
	{
		if(leftDigit > rightDigit)
		{
			//TODO: right string could be only 1 big
			leftDigit += leftNumString[++leftPos] - '0';
		}
		bool isCorrectGuess = false;
		while(!isCorrectGuess)
		{
			int divisionResult = rightDigit / leftDigit;	
			
			huge_integer a (rightNumString.substr(0, rightPos));
			huge_integer b (std::to_string(divisionResult));
			huge_integer c = a * b;
			if(c < right)
			{
			}
			else if(c > right <F11>)
			{
			}
			else
			{
				isCorrectGuess = true;
			}

		}
	}
	return huge_integer("0");
}
huge_integer huge_integer::operator%(const huge_integer right) const
{
	huge_integer divisionResult = *this / right;
	huge_integer multiplicationResult = divisionResult * right;
	return *this - multiplicationResult;
}
//========================
//Comparison Operators
//========================
bool huge_integer::operator<(const huge_integer right) const
{
}
bool huge_integer::operator>(const huge_integer right) const
{
}
bool huge_integer::operator==(const huge_integer right) const
{
}
//========================
//Private Helper Functions
//========================
bool huge_integer::borrow(string & leftString, string & rightString, int leftPos, int rightPos) const
{
	int startingPos = leftPos;

	int leftDigit = leftPos >= 0 ? leftString[leftPos] - '0' : 0;
	int rightDigit = rightPos >= 0 ? rightString[rightPos] - '0' : 0;
	//keep comparing left and right digits untill the highest up one is 
	//found 	
	while(leftDigit < rightDigit)
	{
		leftPos--;
		rightPos--;
		//if it fully traverses the left string and cant borrow, then
		//the string cannot be subtracted (will be negative)
		if(leftPos < 0)
			return false;

		leftDigit = leftPos >= 0 ? leftString[leftPos] - '0' : 0;
		rightDigit = rightPos >= 0 ? rightString[rightPos] - '0' : 0;
	}
	//the last borrow position has been found, now continue to borrow from 
	//leading numbers	
	while(leftPos < startingPos)
	{
		leftString[leftPos] -= 1;
		leftString[leftPos + 1] += 10;
		leftPos++;
	}
	return true;
}


int main(int argc, char* argv[])
{
	
	huge_integer a("10");
	huge_integer b("333333");
	huge_integer c;
        c = a + b;
	
	std::cout << c.get_value() << std::endl;
	c = a * b;
	std::cout << c.get_value() << std::endl;
	huge_integer b("333333");
	huge_integer e("555");
	
	c = d - e;
	std::cout << c.get_value() << std::endl;


	huge_integer x ("8030440");
	huge_integer y ("57433");
	
	c = x / y;
	std::cout << c.get_value() << std::endl;
}
