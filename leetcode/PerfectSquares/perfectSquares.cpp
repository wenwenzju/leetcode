#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		static vector<int> mem;
		cout << mem.size()-1 << endl;
		if (n<=mem.size()-1) return mem[n];
		while(mem.size() != n+1) mem.push_back(0);
		for (int i = 1; i*i <= n; ++i) mem[i*i] = 1;
		return helper(n, mem);
	}
private:
	int helper(int n, vector<int>& mem)
	{
		if (mem[n] > 0) return mem[n];
		int len = n;
		for (int i = 1; i*i <= n; ++i)
		{
			mem[n-i*i] = helper(n-i*i, mem);
			int tmp = 1+mem[n-i*i];
			if (tmp < len) len = tmp;
		}
		mem[n] = len;
		return len;
	}
};

int main()
{
	Solution s;
	cout << s.numSquares(1) << endl;;
}