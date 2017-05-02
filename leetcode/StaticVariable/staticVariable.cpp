#include "classh.h"
#include <string>
using namespace std;

void bar(const string& s)
{
	cout << s << endl;
}


int main()
{
	bar("hello world");
	using namespace std;
	cout << sizeof(TestClass) << endl;
	cout << sizeof(int) << endl;
	TestClass tc(10);
	cout << sizeof(tc) << endl;
	tc.print();
	tc.static_function(100);
	std::cout << TestClass::b<<std::endl;
	TestClass::static_function(1000);
	cout << tc.fuck(1, 2) << endl;
	cout << tc.fuck(1, 2) << endl;
}