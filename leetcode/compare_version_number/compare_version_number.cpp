#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int s1 = 0, s2 = 0;
		int n1 = version1.size(), n2 = version2.size();
		do
		{
			int v1 = 0, v2 = 0, f1 = 0, f2 = 0;
			if (s1 != string::npos)
			{
				v1 = version1.find('.', s1);
				if (v1 == string::npos)
				{
					f1 = stoi(version1.substr(s1));
					s1 = v1;
				}
				else
				{
					f1 = stoi(version1.substr(s1, v1-s1));
					s1 = v1+1>=n1?string::npos:v1+1;
				}
			}
			else
			{
				f1 = 0;
			}
			if (s2 != string::npos)
			{
				v2 = version2.find('.', s2);
				if (v2 == string::npos)
				{
					f2 = stoi(version2.substr(s2));
					s2 = v2;
				}
				else
				{
					f2 = stoi(version2.substr(s2, v2-s2));
					s2 = v2+1>=n2?string::npos:v2+1;
				}
			}
			else 
			{
				f2 = 0;
			}

			if (f1 > f2) return 1;
			if (f1 < f2) return -1;
		}while(s1 != string::npos || s2 != string::npos);
		return 0;
	}
};
int main()
{
	string v1("01"), v2("1");
	Solution s;
	int res = s.compareVersion(v1, v2);
	return 0;
}