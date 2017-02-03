/*
 *Ryan Dougherty 
 *u0534947
 *CS 3505 Assignment 3
 */
#include <iostream>
#include <fstream>
#include <set>
#include <iterator>
#include <gtest/gtest.h>
#include "wordset.h"
#include "node.h"

using namespace std;

/*
 *FILE TESTS
 */
TEST(wordsetTest, fileTest1)
{
	//placing it in its own scope. Used to count number of destructions
	{
		set<string>      stl_set_of_words;
		cs3505::wordset  our_set_of_words(1000);
		cout << "constructed wordset" << endl;

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
		for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
		{
			string s = *it;
			cout << s << endl;
		}
		//check to make sure set size and our custom wordset size are equivalent
		EXPECT_EQ(stl_set_of_words.size(), our_set_of_words.size()) << "STL set size: " << stl_set_of_words.size() << " | custom wordset size: " << our_set_of_words.size();
	}
	//check if wordset was properly created and destroyed
	EXPECT_EQ(cs3505::wordset::get_constructor_count(), cs3505::wordset::get_destructor_count()) << "wordset constructor count: " << cs3505::wordset::get_constructor_count() << " | wordset destructor count: " << cs3505::wordset::get_destructor_count();
	
	cout << endl;

	//check if all nodes were properly created and destroyed
	EXPECT_EQ(cs3505::node::get_constructor_count(), cs3505::node::get_destructor_count()) << "node constructor count: " << cs3505::node::get_constructor_count() << " | node destructor count: " << cs3505::node::get_destructor_count(); 
}

TEST(wordsetTest, fileTest2)
{
	//placing it in its own scope. Used to count number of destructions
	{
		set<string>      stl_set_of_words;
		cs3505::wordset  our_set_of_words(1000);
		cout << "constructed wordset" << endl;

		ifstream in("SavingPrivateRyanScript.txt"); //My favorite movie :)
		
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
		for (set<string>::iterator it = stl_set_of_words.begin(); it != stl_set_of_words.end(); it++)
		{
			string s = *it;
			cout << s << endl;
		}
		//check to make sure set size and our custom wordset size are equivalent
		EXPECT_EQ(stl_set_of_words.size(), our_set_of_words.size()) << "STL set size: " << stl_set_of_words.size() << " | custom wordset size: " << our_set_of_words.size();
	}
	//check if wordset was properly created and destroyed
	EXPECT_EQ(cs3505::wordset::get_constructor_count(), cs3505::wordset::get_destructor_count()) << "wordset constructor count: " << cs3505::wordset::get_constructor_count() << " | wordset destructor count: " << cs3505::wordset::get_destructor_count();
	
	cout << endl;

	//check if all nodes were properly created and destroyed
	EXPECT_EQ(cs3505::node::get_constructor_count(), cs3505::node::get_destructor_count()) << "node constructor count: " << cs3505::node::get_constructor_count() << " | node destructor count: " << cs3505::node::get_destructor_count(); 
}
/*
 *REMOVE TESTS
 */
TEST(wordsetTest, removeStandard)
{
	//tests to make sure remove does its job
	cs3505::wordset w(100);
	w.add("hello");
	w.add("hi");
	w.add("bonjour");
	w.add("good-day");
	w.remove("hello");
	ASSERT_FALSE(w.contains("hello"));
}
TEST(wordsetTest, removeBlank)
{
	//tests that the wordset will handle nonexisting
	//removes gracefully
	cs3505::wordset w(100);
	w.remove("hello");
	ASSERT_TRUE(true);
}
TEST(wordsetTest, removeNULL)
{
	//tests removal of a NULL value
	cs3505::wordset w(100);
	w.remove(NULL);
	ASSERT_TRUE(true);
}

/*
 *GET CONTENTS TESTS
 */
TEST(wordsetTest, getElementsStandard)
{	
	//tests that the vector has correct length and
	//unique values
	cs3505::wordset w(100);
	w.add("hello");
	w.add("hi");
	w.add("hi");
	w.add("bonjour");
	w.add("good-day");
	std::vector<std::string> vec = w.get_elements();
	ASSERT_EQ(4 ,vec.size());
	for(std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++ )
	{
		ASSERT_TRUE(w.contains(*it));
		w.remove(*it);
	}
}
TEST(wordset, getElementsBlank)
{
	//checks to make sure a blank wordset returns
	//a blank vector
	cs3505::wordset w(100);
	std::vector<std::string> vec = w.get_elements();
	ASSERT_EQ(0, vec.size());
}
TEST(wordset, assignmentStandard)
{
	//tests that two wordsets are equal
	//when assigned to eachother
	cs3505::wordset w(100);

	w.add("hello");
	w.add("hi");
	w.add("bonjour");
	w.add("good-day");
	w.remove("hello");

	cs3505::wordset x = w;
	ASSERT_EQ(x.size(), w.size());
	std::vector<std::string> vec1 = w.get_elements();
	std::vector<std::string> vec2 = x.get_elements();
	for(int i = 0; i < vec1.size(); i++)
	{
		EXPECT_EQ(vec1[i], vec2[i]) << "Vectors were not equal at index: " << i << " | vec1: " << vec1[i] << ", vec2: " << vec2[i] << std::endl; 
	}
}
TEST(wordset, assignmentCompareNodes)
{
	//test to make sure node's next values dont
	//point to the same address
	cs3505::wordset ws1(100);

	ws1.add("hello");
	ws1.add("hi");
	ws1.add("bonjour");
	ws1.add("good-day");
	ws1.add("aloha");

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
	ASSERT_EQ(vec1.size(), 0);
	ASSERT_EQ(vec2.size(), 5);
	
	for(int i = 0; i < 5; i++)
	{
		ASSERT_NE(vec2[i], NULL);	
	}
}

int main (int argc, char**argv)
{
	/* I used GoogleTest as my testing framework. Compiling and running this file will execute the tests.
	 * Running the MakeFile will also run the tests.
	 */
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
