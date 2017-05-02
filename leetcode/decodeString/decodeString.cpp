#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int n = s.size();
		if (n<=3) return s;
		string res;
		stack<pair<int,int>> brackets;
		int i = 0;
		for (; i < n; ++i) 
		{
			if (isdigit(s[i]))
			{
				int k = i++;
				while (i < n && isdigit(s[i])) i++;
				brackets.push(pair<int,int>(res.size(), stoi(s.substr(k,i-k))));
				i++;
				break;
			}
			res+=s[i];
		}
		while (!brackets.empty() || i < n)
		{
			if (isdigit(s[i]))
			{
				int k = i++;
				while (i < n && isdigit(s[i])) i++;
				brackets.push(pair<int,int>(res.size(), stoi(s.substr(k,i-k))));
				i++;
				continue;
			}
			if (s[i] == ']')
			{
				int start = brackets.top().first;
				int repeat = brackets.top().second-1;
				brackets.pop();
				string tmp = res.substr(start);
				while (repeat--)
				{
					res+=tmp;
				}
			}
			else res+=s[i];
			i++;
		}
		return res;
	}
};

int main()
{
	string str("3[a]2[bc]");
	Solution s;
	string res = s.decodeString(str);
}