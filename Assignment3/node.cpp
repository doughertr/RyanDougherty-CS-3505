#include "node.h";
#include <string>

namespace Cs3505_Assignment3
{
	/*
	 * Initializing Node static variables
	 */
	long long node::constructor_count = 0;
	long long node::destructor_count = 0;

	/*
	 * Node public function declarations
	 */
	node::node(const std::string & val) : data(val)
	{
		node::constructor_count++;
		this->next = NULL;
	}
	node::~node()
	{
		node::destructor_count++;
		this->next = NULL;
		//TODO: Add recursive destruction
	}
	node& node::operator=(const node & val)
	{
		this->data = val.data;
		this->next = val.next;	
		return *this;
	}
	std::string node::get_data() const
	{
		return data;
	}

	long long node::get_constructor_count()
	{
		return constructor_count;
	}
	long long node::get_destructor_count()
	{
		return destructor_count;
	}


}
