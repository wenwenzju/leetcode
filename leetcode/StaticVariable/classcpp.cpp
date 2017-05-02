#include "classh.h"

int TestClass::b = 0;

TestClass::TestClass(int v)
{
	a = v;
	b = a;
}

// inline void TestClass::print() const
// {
// 	std::cout << "a = " << a << "; b = " << b << std::endl;
// }

void TestClass::static_function(int v)
{
	std::cout << "static function " << v << std::endl;
}