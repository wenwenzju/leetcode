#include <iostream>
class TestClass
{
public:
	int a;
	double c;
	static int b;
	TestClass(int v);
	inline void print() const {std::cout << "a = " << a << "; b = " << b << std::endl;};
	int fuck(int v1, int v2){a = v1; c = v2; return 0;}
	int fuck(int v1, int v2) const {std::cout << "a = " << a << "; c = " << c << std::endl; return 1;}
	static void static_function(int v);
};