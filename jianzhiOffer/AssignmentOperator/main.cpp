#include "assignment_operator.h"
#include <iostream>

int main()
{
	CMyString s1("Song Yun");
	CMyString s2(s1);
	s2 = s2;
	CMyString s3;
	s3 = s1 = s2 = s1/* = s2 = s2*/;

	char c[] = "abcdef";
	using namespace std;
	cout << sizeof(c) << endl;
	cout << strlen(c) << endl;
}