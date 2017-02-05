/*
 *Ryan Dougherty 
 *u0534947
 *CS 3505 Assignment 3
 */
#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include "wordset.h"
#include "node.h"

using namespace std;

template<typename T>
void test_equality(T left, T right, string check)
{
	cout << "checking for: " << check << "..." << endl;
	if(left == right)
	{
		cout << "-------Two Objects are Equal-------" << endl;	
	}
	else
	{
		cout << "-------Two Objects are Not Equal-------" << endl;
	}
	cout << endl;
}



/*
 *FILE TESTS
 */
void fileTest1()
{
	cout << "Testing file 1: Bee movie script" << endl;
	//placing it in its own scope. Used to count number of destructions
	{
		set<string>      stl_set_of_words;
		cs3505::wordset  our_set_of_words(1000);

		ifstream in("EntireBeeMovieScript.txt"); //because, you know, why not?
		
		while (true)
		{
			string word;
			in >> word;
			//continue reading words from the file until it fails
			if (in.fail())
				break;
			stl_set_of_words.insert(word);
			our_set_of_words.add(word);
		}

		// Close the file.
		in.close();

	        cout << "STL set size: " << stl_set_of_words.size() << endl;
	       	cout << "custom wordset size: " << our_set_of_words.size() << endl;
		test_equality((int)stl_set_of_words.size(), (int)our_set_of_words.size(),"Set and wordset size equality");
	}
	//check if wordset was properly created and destroyed
	cout << "wordset constructor count: " << cs3505::wordset::get_constructor_count() << endl;
	cout << "wordset destructor count: " << cs3505::wordset::get_destructor_count() << endl;
	test_equality((int) cs3505::wordset::get_destructor_count(), (int)cs3505::wordset::get_destructor_count(), "Wordset construtor and destructor equality");
		
	cout << endl;

	//check if all nodes were properly created and destroyed
	cout << "node constructor count: " << cs3505::node::get_constructor_count() << endl;
        cout <<	"node destructor count: " << cs3505::node::get_destructor_count() << endl;
	test_equality((int) cs3505::node::get_constructor_count(), (int) cs3505::node::get_destructor_count(), "Node constructor and destructor equality");
	//reset constructor and destructor counts for node and wordset
	cs3505::wordset::reset_counters();
	cs3505::node::reset_counters();
}


void fileTest2()
{
	cout << "Testing file 2: Saving Private Ryan Script" << endl;
	//placing it in its own scope. Used to count number of destructions
	{
		set<string>      stl_set_of_words;
		cs3505::wordset  our_set_of_words(1000);

		ifstream in("SavingPrivateRyanScript.txt"); //because, you know, why not?
		
		while (true)
		{
			string word;
			in >> word;
			//continue reading words from the file until it fails
			if (in.fail())
				break;
			stl_set_of_words.insert(word);
			our_set_of_words.add(word);
		}

		// Close the file.
		in.close();

	        cout << "STL set size: " << stl_set_of_words.size() << endl;
	       	cout << "custom wordset size: " << our_set_of_words.size() << endl;
		test_equality((int)stl_set_of_words.size(), (int)our_set_of_words.size(),"Set and wordset size equality");
	}
	//check if wordset was properly created and destroyed
	cout << "wordset constructor count: " << cs3505::wordset::get_constructor_count() << endl;
	cout << "wordset destructor count: " << cs3505::wordset::get_destructor_count() << endl;
	test_equality((int) cs3505::wordset::get_destructor_count(), (int)cs3505::wordset::get_destructor_count(), "Wordset construtor and destructor equality");
		
	cout << endl;

	//check if all nodes were properly created and destroyed
	cout << "node constructor count: " << cs3505::node::get_constructor_count() << endl;
        cout <<	"node destructor count: " << cs3505::node::get_destructor_count() << endl;
	test_equality((int) cs3505::node::get_constructor_count(), (int) cs3505::node::get_destructor_count(), "Node constructor and destructor equality");
	//reset constructor and destructor counts for node and wordset
	cs3505::wordset::reset_counters();
	cs3505::node::reset_counters();
}
/*
 *REMOVE TESTS
 */

void removeStandardTest()
{
	//tests to make sure remove does its job
	cs3505::wordset w(100);
	cout << "adding words.." << endl;
	w.add("hello");
	w.add("hi");
	w.add("bonjour");
	w.add("good-day");
	cout << "removing hello" << endl;
	w.remove("hello");
	cout << endl;	
	test_equality(w.contains("hello"), false, "Wordset does not contain hello");
}
void removeBlankTest()
{
	cout << "Testing for blank word removal" << endl;
	//tests that the wordset will handle nonexisting
	//removes gracefully
	cs3505::wordset w(100);
	w.remove("hello");
}
/*
 *GET CONTENTS TESTS
 */
void getContentsStandardTest()
{	
	cout << "Testing for standard get_contents" << endl;
	//tests that the vector has correct length and
	//unique values
	cs3505::wordset w(100);
	cout << "adding 4 words..." << endl;
	w.add("hello");
	w.add("hi");
	w.add("hi");
	w.add("bonjour");
	w.add("good-day");
	std::vector<std::string> vec = w.get_elements();
	test_equality(4 ,(int)vec.size(), "Wordset size is equal to 4");
	for(std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it )
	{
		string iterVal = *it;
		test_equality(true, w.contains(*it), "Word set contains word: " + *it);
		w.remove(*it);
	}
}
void getElementsBlankTest()
{
	cout << "Testing for blank get_elements" << endl;
	//checks to make sure a blank wordset returns
	//a blank vector
	cs3505::wordset w(100);
	std::vector<std::string> vec = w.get_elements();
	test_equality(0, (int) vec.size(), "Blank wordset vector size is 0");
}
void standardAssignmentTest()
{
	cout << "Testing standard assignment" << endl;
	//tests that two wordsets are equal
	//when assigned to eachother
	cs3505::wordset w(100);
	cout << "adding words..." << endl;
	w.add("hello");
	w.add("hi");
	w.add("bonjour");
	w.add("good-day");
	w.remove("hello");
	
	cout << "assigning wordset x to y" << endl;
	cs3505::wordset x = w;
	test_equality(x.size(), w.size(), "Wordset sizes are the same");
	std::vector<std::string> vec1 = w.get_elements();
	std::vector<std::string> vec2 = x.get_elements();
	for(int i = 0; i < vec1.size(); i++)
	{
		test_equality(vec1[i], vec2[i], "Wordset vector 1 is equal to wordset vector 2");
	}
}
void assignmentCompareNodesTest()
{
	cout << "Testing comparing nodes with assignment" << endl;
	//test to make sure node's next values dont
	//point to the same address
	cs3505::wordset ws1(100);
	cout << "adding words..." << endl;
	ws1.add("hello");
	ws1.add("hi");
	ws1.add("bonjour");
	ws1.add("good-day");
	ws1.add("aloha");

	cout << "removing words..." << endl;
	cs3505::wordset ws2 = ws1;
	ws1.remove("hello");
	ws1.remove("hi");
	ws1.remove("bonjour");
	ws1.remove("good-day");
	ws1.remove("aloha");

	std::vector<std::string> vec1 = ws1.get_elements();
	std::vector<std::string> vec2 = ws2.get_elements();

	//if the wordsets are not pointing to the same nodes,
	//then the element vectors will be different sizes 
	//and vector 2's values will not equal null
	test_equality((int)vec1.size(), 0, "Vec1's size is equal to zero");
	test_equality((int)vec2.size(), 5, "Vec2's size is equal to 5");
	
}

int main (int argc, char**argv)
{
//	testing::InitGoogleTest(&argc, argv);
//	return RUN_ALL_TESTS();
	fileTest1();
	fileTest2();

	removeStandardTest();
	removeBlankTest();

	getContentsStandardTest();
	getElementsBlankTest();

	standardAssignmentTest();
	assignmentCompareNodesTest();
}
