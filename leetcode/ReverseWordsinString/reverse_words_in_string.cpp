#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		reverse(s.begin(), s.end());
		int n = s.size();
		for (int i = 0; i < n;)
		{
			while (i < n && s[i] == ' ') i++;
			if (i==n) break;
			int j = i;
			while (i < n && s[i] != ' ') i++;
			int k = i-1;
			while (j < k) {swap(s[j],s[k]); j++; k--;}
		}
		int i = 0;
		while (i < n && s[i] == ' ') {s.erase(i,1);n--;}
		if (n==0) return;
		for (; i < n-1;)
		{
			while (i < n-1 && s[i] == ' ' && s[i+1] == ' ') {s.erase(i,1);n--;}
			i++;
			while (i < n && s[i] != ' ') i++;
		}
		i = n-1;
		while ( i >= 0 && s[i] == ' ') {s.erase(i,1);i--;}
	}
};

int main()
{
	string s("   Yun   ");
	Solution sol;
	sol.reverseWords(s);
}