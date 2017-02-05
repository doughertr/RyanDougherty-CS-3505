/*
 *Ryan Dougherty 
 *u0534947
 *CS 3505 Assignment 3
 */
#include "wordset.h"
#include "node.h"
#include <iostream>
#include <string>
#include <vector>
namespace cs3505
{
	/*
	 * Static variable intializations
	 */
	long long wordset::constructor_count = 0;
	long long wordset::destructor_count = 0;

	long long wordset::get_constructor_count()
	{
		return constructor_count;
	}
	long long wordset::get_destructor_count()
	{
		return destructor_count;
	}
	void wordset::reset_counters()
	{
		wordset::constructor_count = 0;
		wordset::destructor_count = 0;
	}
	/*
	 * Public function declarations
	 */
	wordset::wordset(int capacity) 
	{
		this->capacity = capacity;
		this->count = 0;
		this->table = new node*[capacity];

		//set every node in the table to NULL
		//or else you're gonna have a bad time
		for(int i = 0; i < capacity; i++)
		{
			table[i] = NULL;
		}
		constructor_count++;
	}
	wordset::wordset(const wordset & other) 
	{ 
		this->capacity = 0;
		this->count = 0;
		this->table = NULL;

		*this = other;
		constructor_count++;
	}
	wordset::~wordset()
	{
		destructor_count++;
		clean();
	}
	wordset& wordset::operator=(const wordset & right)
	{
		//check if the objects share the same address
		if(this == &right)
			return *this;
		clean();

		capacity = right.capacity;
		this->table = new node*[capacity];

		for(int i = 0; i < capacity; i++)
		{
			//if the other table has no nodes,
			//then continue iterating 
			if(right.table[i] == NULL)
			{
				this->table[i] = NULL;
				continue;
			}
			node *current = right.table[i];
			while(current != NULL)
			{
				this->add(current->data);
				current = current->next;
			}
		}
		return *this;
	}

	void wordset::add (const std::string & val)
	{
		//handle empty and NULL strings
		if(val.empty())
			return;


		int index = hash(val);
		node *current = table[index], *previous = NULL;

		while(current != NULL)
		{
			//check if string already exists in set
			//if it does, ignore it and break out
			if(current->data == val)
				return;

			//traverse to next node, but store previous node
			//in case we run into the end of the list
			previous = current;
			current = current->next;
		}

		current = new node(val);

		//if previous value doesn't exist, then
		//it must be the first value to enter the bucket
		if(previous == NULL)
			table[index] = current;
		//if it exists then set the next node in
		//the bucket to current
		else
			previous->next = current;

		count++;
	}
	void wordset::remove(const std::string & val)
	{
		//handle empty and NULL strings
		if(val.empty())
			return;

		int index = hash(val);
		node *current = table[index], *nxt = NULL, *previous = NULL;
		while(current != NULL)
		{
			if(current->data == val)
			{
				nxt = current->next;
				delete current;
				if(previous == NULL)
					table[index] = NULL;
				else
					current = nxt;
				count--;
			}
			previous = current;
			current = current->next;
		}
	}
	bool wordset::contains(const std::string & val) const
	{ 
		int index = hash(val);
		node *current = table[index];
		while(current != NULL)
		{
			//found the value!
			if(current->data == val)
				return true;
			current = current->next;
		}
		//did not find the value :(
		//starting val reference now refers to last node
		return false;
	}
	int wordset::size() const
	{
		return count;
	}
	std::vector<std::string> wordset::get_elements() const
	{
		std::vector<std::string> elementVect;

		for(int i = 0; i < capacity; i++)
		{
			//if table is empty, move on
			if(table[i] == NULL)
				continue;
			node *current = table[i];
			while(current != NULL)
			{
				//add to the vector the current node's data
				elementVect.push_back(current->data);
				current = current->next;
			}
		}
		return elementVect;
	}
	/*
	 * Private function definitions
	 */
	int wordset::hash (const std::string & val) const
	{
		long long hash = 0;
		for(int i = 0; i < val.length(); i++)
			hash = ((hash * 1117) + val[i]) % capacity;
		return static_cast<int>(hash);
	}
	void wordset::clean()
	{
		//return if the table is not set to anything
		if(table == NULL)
			return;

		for(int i = 0; i < capacity; i++)
		{
			node * current = table[i];
			table[i] = NULL;
			while(current != NULL)
			{
				//advance the node and delete current
				node * nxt = current->next;
				delete current;
				current = nxt;
			}
		}
		//delete the table pointer
		delete [] table;
		table = NULL;
		capacity = 0;
		count = 0;
	}

}

