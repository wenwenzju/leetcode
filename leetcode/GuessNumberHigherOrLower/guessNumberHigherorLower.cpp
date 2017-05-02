#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int getMoneyAmount(int n) {
		if (n <= 1) return 0;
		static vector<vector<int>> mem;
		if (n <= (int)mem.size()-1) return mem[1][n];
		for (int i = 0; i < mem.size(); ++i) mem[i].insert(mem[i].end(), n+1-mem.size());
		for (int i = mem.size(); i<= n; ++i) mem.push_back(vector<int>(n+1));
		return helper(1, n, mem);
	}
private:
	int helper(int s, int e, vector<vector<int>>& mem)
	{
		if (s >= e) return 0;
		if (mem[s][e] > 0) return mem[s][e];
		if (e-s == 1) {mem[s][e] = s;return s;}
		if (e-s == 2) {mem[s][e] = s+1;return s+1;}
		int m = INT_MAX;
		for (int i = s; i <= e; ++i)
		{
			int t1, t2, t;
			if (i == s) {t1 = 0; t2 = helper(i+1, e, mem);mem[i+1][e] = t2;}
			else if (i == e) {t1 = helper(s, i-1, mem); t2 = 0;mem[s][i-1] = t1;}
			else {t1 = helper(s, i-1, mem); mem[s][i-1] = t1; t2 = helper(i+1, e, mem); mem[i+1][e] = t2;}
			t = max(i+t1, i+t2);
			if (m > t) m = t;
		}
		mem[s][e] = m;
		return m;
	}
};
int main()
{
	Solution s;
	s.getMoneyAmount(10);
	s.getMoneyAmount(124);
	return 1;
}