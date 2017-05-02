#include <iostream>

class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		return climbStairs(n-1)+climbStairs(n-2);
	}
};

//bottom up
class Solution1 {
public:
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;
		if (n == 2) return 2;
		int current = 1, previous = 0;
		for (int i = 0; i <= n-1; ++i)
		{
			int newn = current + previous;
			previous = current;
			current = newn;
		}
		return current;
	}
};
using namespace std;
int main()
{
	Solution1 s;
	int n;
	while(cin >> n)
		cout << "result: " << s.climbStairs(n) << endl;
	return 0;
}