/*
 * Assignment 1
 * Ryan Dougherty
 * CS 3505 
 * 2017
 */



#include <iostream>

using namespace std;

int main()
{
	cout << "Enter an integer: ";
	int num;
	cin >> num;

	if(cin.fail())
	{
		cout << "composite" << endl;
		return 1;
	}
	else
	{
		if(num <= 0)
		{
			cout << "composite" << endl;
			return 1;
		}
		if(num > 0 && num <= 2)
		{
			cout << "prime" << endl;
			return 1;
		}
		for(int i = 2; i < num; i++)
		{
			if(num % i == 0)
			{
				cout << "composite" << endl;
				return 1;
			}
		}
		cout << "prime" << endl;
		return 1;
	}
}
