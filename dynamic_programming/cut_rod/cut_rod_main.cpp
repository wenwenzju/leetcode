#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int cut_rod0(int* p, int n)
	{
		vector<int> r(n+1, -1);
		return cut_rod_up_bottom(p, n, r);
	}
	int cut_rod1(int* p, int n)
	{
		vector<int> r(n+1, 0);
		return cut_rod_bottom_up(p, n, r);
	}
private:
	int cut_rod_up_bottom(int* p, int n, vector<int>& r)
	{
		if (r[n] >= 0) return r[n];
		int q = -1;
		if (n == 0) q = 0;
		else
		{
			for (int i = 1; i <= n; ++i)
			{
				q = max(q, p[i]+cut_rod_up_bottom(p, n-i, r));
			}
		}
		r[n] = q;
		return q;
	}
	int cut_rod_bottom_up(int* p, int n, vector<int>& r)
	{
		r[0] = 0;
		if (n == 0) return 0;
		for (int i = 1; i <= n; ++i)
		{
			int q = -1;
			for (int j = 1; j <= i; ++j)
			{
				q = max(q, p[j]+r[i-j]);
			}
			r[i] = q;
		}
		return r[n];
	}
};

int main()
{
	Solution s;
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};
	int n = 10;
	cout << s.cut_rod0(p, n) << endl;
	cout << s.cut_rod1(p, n) << endl;
}