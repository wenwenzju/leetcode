#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int n = strs.size(); if (n == 0) return vector<vector<string>>();
		vector<vector<int>> table(n, vector<int>(26, 0));
		for (int i = 0; i < n; ++i)
		{
			int s = strs[i].size();
			for (int j = 0; j < s; ++j) table[i][strs[i][j]-'a']++;
		}
		unordered_map<vector<int>, int> m;
		vector<vector<string>> res;
		for (int i = 0; i < n; ++i)
		{
			if (m.count(table[i]) > 0) res[m[table[i]]].push_back(strs[i]);
			else
			{
				m[table[i]] = res.size();
				res.push_back(vector<string>(1, strs[i]));
			}
		}
		return res;
	}
};

int main()
{
	unordered_map<vector<int>, int> ma;
	vector<string> strs; strs.push_back(string(""));
	Solution s;
	vector<vector<string>> res = s.groupAnagrams(strs);
	return 1;
}