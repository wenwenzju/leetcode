#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int inc0 = nums[0], exc0 = 0;
		//rob first house
		int inc = 0, exc = 0;
		int fuck = nums.size()-2;
		for (int i = 2; i < nums.size()-2; ++i)
		{
			int tmp = inc;
			inc = exc+nums[i];
			exc = max(tmp, exc);
		}
		inc0 += max(inc, exc);

		//don't rob first
		inc = 0; exc = 0;
		for (int i = 1; i < nums.size()-1; ++i)
		{
			int tmp = inc;
			inc = exc+nums[i];
			exc = max(tmp, exc);
		}
		exc0 += max(inc, exc);
		return max(inc0, exc0);
	}
};

int main()
{
	Solution s;
	vector<int> nums; nums.push_back(0);
	int res = s.rob(nums);
	return 0;
}