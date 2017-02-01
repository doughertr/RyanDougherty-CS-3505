#ifndef NODE_H
#define NODE_H

#include <string>

namespace cs3505
{
	class node
	{
		//allows for wordset to access node's privates (heehee)
		friend class wordset;

		public:
			static long long get_constructor_count();
			static long long get_destructor_count();
			node & operator=(const node & val);
			std::string get_data() const;
		private:
			node(const std::string & val);
			~node();

			std::string data;
			node* next;	

			static long long constructor_count;
			static long long destructor_count;
	};
}
#endif
