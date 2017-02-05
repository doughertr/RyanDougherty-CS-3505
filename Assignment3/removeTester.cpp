#include <iostream>
#include <vector>
#include <string>
#include "node.h"
#include "wordset.h"

int main(int argc, char **argv)
{
	cs3505::wordset w(100);
	w.add("hello");
	w.add("goodbye");
	w.add("why");
	w.add("do");
	w.add("you");
	w.add("say");
	w.add("goodbye");
	w.add("when");
	w.add("I");
	w.add("say");
	w.add("hello");

	w.remove("goodbye");
	bool saysHello = w.contains("hello");
	bool saysGoodbye = w.contains("goodbye");
	std::cout << "contains hello: " << saysHello << std::endl;
	std::cout << "contains goodbye: " << saysGoodbye << std::endl;	
}
