#ifndef WORDSET_H
#define WORDSET_H

#include <string>

namespace Cs3505_Assignment3
{
	class node;

	class wordset
	{
		public:
			wordset(int capacity = 100);
			wordset(const wordset & other);
			~wordset();

			void add(const std::string & val);
			void remove(const std::string & val);
			bool contains(const std::string & val) const;
			int size() const;

			wordset & operator= (const wordset & right);

			static long long get_constructor_count();
			static long long get_destrcutor_count();
		private:
			int hash_val(const std::string val);
			void clean();
			bool find(node* & searchVal, const node* & startingVal) const;
				
			int capacity;
			int count;
			node** table;

			static long long constructor_count;
			static long long destructor_count;
	};	
}
#endif
