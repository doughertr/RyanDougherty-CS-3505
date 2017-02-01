#include <iostream>
#include <vector>
#include <boost/foreach.hpp>

using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	
	cout << "standard: " << endl;
	//standard format
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << endl;

	cout << "iterator: " << endl;	
	//iterator format
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		cout << *it << endl;

	cout << "boost: " << endl;
	//boost format
	BOOST_FOREACH(int i, vec)
	{
		cout << i << endl;
	}

	//sets 
}

