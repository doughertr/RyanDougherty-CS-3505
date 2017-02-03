/*
 *Ryan Dougherty 
 *u0534947
 *CS 3505 Assignment 3
 */
#ifndef WORDSET_H
#define WORDSET_H

#include <string>
#include <vector>

namespace cs3505
{
	class node;

	class wordset
	{
		public:
			wordset(int capacity = 100);
			wordset(const wordset & other);
			~wordset();


			wordset & operator= (const wordset & right);
			
			//adds to the wordset a unique word
			void add(const std::string & val);
			//removes an existing word from the wordset
			void remove(const std::string & val);
			//returns true if that word exists in the wordset
			bool contains(const std::string & val) const;
			int size() const;

			/* 
			 * This function populates and returns a std::vector<std::string>
		         * with elements from this set.  The elements in the vector will be in the
		         * same order as the natural ordering in this hashtable (table[0] first, etc.).
		         * The size of the vector will be exactly equal to the element count
		         * in this hashtable.
			 */
		 	std::vector<std::string> get_elements() const;

			
			static long long get_constructor_count();
			static long long get_destructor_count();
		private:
			int hash(const std::string & val) const;
			void clean();
				
			int capacity;
			int count;
			node** table;

			static long long constructor_count;
			static long long destructor_count;
	};	
}
#endif
