#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		int n = nums.size();
		if (n==0) return false;
		int s = 0;
		for (int i = 0; i < n; ++i) s+=nums[i];
		if (n%4) return false;
		int l = n/4;
		vector<int> flags(n,0);
	}
	bool findSum(vector<int>& nums, int l, vector<int>& flags, int k, int turn)
	{
		if (l == 0) {/*flags[k] = turn;*/return true;}
		if (l < 0) {/*flags[k] = 0;*/ return false;}
		if (k >= nums.size()) return false;
		while (k<flags.size()&&flags[k]) ++k;
		if (nums[k] <= l && !flags[k])
		{
			if (findSum(nums, l-nums[k], flags, k+1, turn)) flags[k] = turn;
			else flags[k] = 0;
		}
		if (!flags[k]) if (findSum(nums, l, flags, k+1, turn)) flags[k] = 0;
	}
};

int main()
{
	Solution s;
	vector<int> nums(8);for (int i = 0; i < nums.size(); ++i) nums[i] = i+1;
	vector<int> flags(8,0);
	s.findSum(nums, 9, flags, 0, 1);
	s.findSum(nums, 9, flags, 0, 2);
	s.findSum(nums, 9, flags, 0, 3);
	s.findSum(nums, 9, flags, 0, 4);
}