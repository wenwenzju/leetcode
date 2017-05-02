#include <iostream>
using namespace std;

class A
{
public:
	virtual void f1(){cout << "A: f1()" << endl;}
	virtual void f2() {f1();}
};

class B : public A
{
public:
	void f1() {cout << "B: f1()" << endl;}
};

int main()
{
	B* b = new B;
	//b->f1();
	b->f2();
}