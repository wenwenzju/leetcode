#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int lengthLongestPath(string input) {
		int n = input.size(); if (n==0)return 0;
		int maxLen = 0, curLen = 0;
		int i = 0;
		stack<pair<int,int>> s;
		while (i < n && input[i] != '\n') i++;
		curLen += i+1;
		if (isFile(input, 0, i)) maxLen = curLen-1;
		s.push(pair<int,int>(0,curLen));
		int preDepth = 0;
		while (i < n)
		{
			int curDepth = skip(input, i);
			int j = i;
			while (i < n && input[i] != '\n') i++;
			int subLen = i-j+1;

			if (curDepth == preDepth)
			{
				curLen -= s.top().second;
				s.pop();
			}
			else if (curDepth < preDepth)
			{
				while (curDepth < preDepth)
				{
					curLen -= s.top().second;
					s.pop();
					preDepth = s.top().first;
				}
				curLen -= s.top().second;
				s.pop();
			}
			curLen += subLen;
			s.push(pair<int,int>(curDepth,subLen));
			preDepth = curDepth;
			if (isFile(input, j, i))
			{
				if (curLen > maxLen) maxLen = curLen-1;
			}
		}
		return maxLen;
	}
private:
	int skip(string& s, int& i)
	{
		int cnt = 0;
		while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		{
			if (s[i]=='\t') cnt += 4;
			else if (s[i] == ' ') cnt += 1;
			i++;
		}
		return cnt;
	}
	bool isFile(string& s, int j, int i)
	{
		for (; j < i; ++j) if (s[j] == '.') return true;
		return false;
	}
};

int main()
{
	string input("dir\n        file.txt");
	cout << input << endl;
	Solution s;
	cout << s.lengthLongestPath(input);
	return 1;
}