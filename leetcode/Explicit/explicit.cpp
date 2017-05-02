#include <iostream>
using namespace std;
class Test1
{
public:
	Test1 (int n){m=n;}
private:
	int m;
};

class Test2
{
public:
	explicit Test2 (int n){m=n;}
private:
	int m;
};

int main()
{
	Test1 t1 = 10;
	double n = 10.;
	Test1 t3(n);
	Test2 t2(n);

	char* p = "12345";
	cout << sizeof(p) << endl;
	cout << strlen(p) << endl;
	cout << sizeof(long) << endl;
}