/*
 * Assignment 1
 * Ryan Dougherty
 * CS 3505
 * 2017
 */


#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	cout << "Enter a weight (in lbs): ";
	double weight;
	cin >> weight;
	if(cin.fail())
	{
		cout << "Invalid input." << endl;
	}
	else
	{
		weight = weight * 0.453592;
		cout << setprecision(2) << fixed << weight << " kg" << endl;
	}
	return 0;
}
