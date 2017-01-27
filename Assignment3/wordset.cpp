#include "wordset.h"
#include "node.h"
#include <iostream>
#include <string>
namespace Cs3505_Assignment3
{
/*
 * Static variable intializations
 */
	long long wordset::constructor_count = 0;
	long long wordset::destructor_count = 0;

/*
 * Public function declarations
 */	
	wordset::wordset(int capacity) : 
		capacity(capacity),
		count(0)
	{
		table = new node*[capacity];
		
		//set every node in the table to NULL
		//or else you're gonna have a bad time
		for(int i = 0; i < capacity; i++)
		{
			table[i] = NULL;
		}		
	}
	wordset::wordset(const wordset & other) :
		capacity(0),
		count(0),
		table(NULL)
	{ 
		constructor_count++;
		*this = other;
	}
	wordset::~wordset()
	{
		destructor_count++;
		clean();
	}

	void wordset::add (const std::string & val)
	{
		int index = hash_val(val);
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
		//it must be the first value to enter
		//the bucket
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
		int 
	}
	/*
	 * Private function impletmentation
	 */
	bool wordset::find(node* & searchVal, const node* & startingVal) const
	{ 
		node* previous = NULL;
		node* current = startingVal;
		while(current != NULL)
		{
			if(current->data == searchVal->data)
			{
				//set the search val
				searchVal = current;
				return true;
			}
			previous = current;
			current = current->next;
		}
		return false;
	}	
}
