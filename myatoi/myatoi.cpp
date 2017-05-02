#include <iostream>

using namespace std;

class Solution
{
public:
	static int myatoi(string str)
	{
		if (0 == str.size()) return 0;
		bool positive = true;
		string only_digits;
		int i = 0;
		int res = 0;
		while (i < str.size()&&str[i] == ' ') ++i;
		if ( i < str.size() && str[i] == '-') {positive = false;++i;}
		else if ( i < str.size() && str[i] == '+') {positive = true; ++i;}
		for (; i < str.size();++i)
		{
			//if (str[i] == '-') {positive = false; continue;}
			if (str[i] < '0' || str[i] > '9') break;
			only_digits += str[i];
		}
		if (0 == only_digits.size()) return 0;
		if (only_digits.size() > 10) 
		{
			if (positive) return INT_MAX;
			else return INT_MIN;
		}
		else if (only_digits.size() == 10)
		{
			if (positive) 
			{
				if (only_digits.compare("2147483647") >= 0) return INT_MAX;
			}
			else
			{
				if (only_digits.compare("2147483648") >= 0) return INT_MIN;
			}
		}
		for (int j = 0; j < only_digits.size(); ++j)
		{
			res = res*10 + only_digits[j]-'0';
		}
		return positive?res:-res;
	}
};

int main(int argc, char* argv[])
{
	string str(argv[1]);
	cout << str.c_str() << endl;
	cout << atoi(str.c_str()) << endl;
	cout << Solution::myatoi(str) << endl;
}