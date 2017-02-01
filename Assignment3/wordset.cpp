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

	long long wordset::get_constructor_count()
	{
		return constructor_count;
	}
	long long wordset::get_destrcutor_count()
	{
		return destructor_count;
	}
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
				continue;
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
		int index = hash(val);
		node *currentNode = table[index], *previousNode = NULL, *nextNode = NULL;

		while(currentNode->data != val)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;

			//returns if it cannot find the value
			if(currentNode == NULL)
				return;
		}
		//next node is the node following the node
		//we want to remove
		nextNode = currentNode->next;

		//set the removed node's pointer to NULL
		//and remove it from the heap
		currentNode->next = NULL;
		delete currentNode;

		//set the previous node's next value 
		//to the node following the removed node
		previousNode->next = nextNode;

		count--;
	}
	/*
	 * Private function impletmentation
	 */
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
		if(table == NULL)
			return;
		for(int i = 0; i < capacity; i++)
		{
			node * current = table[i];
			table[i] = NULL;
			while(current != NULL)
			{
				node * next = current->next;
				delete current;
				current = next;
			}
		}
		delete [] table;
		capacity = 0;
		count = 0;
	}
		
}
