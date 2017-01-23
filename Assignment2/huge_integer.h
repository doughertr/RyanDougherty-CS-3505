#ifndef HUGE_INTEGER
#define HUGE_INTEGER

#include <string>

class huge_integer
{
private:
	std::string val;
	bool borrow(std::string & leftString, std::string & rightString, int leftPos, int rightPos) const;
public:
	huge_integer(const std::string & s);
	huge_integer();
	huge_integer(const huge_integer & other);
	
	std::string get_value() const;

	huge_integer& operator=(const huge_integer right);
	huge_integer operator+(const huge_integer right) const;
	huge_integer operator-(const huge_integer right) const;
	huge_integer operator*(const huge_integer right) const;
	huge_integer operator/(const huge_integer right) const;
	huge_integer operator%(const huge_integer right) const;
};
#endif
