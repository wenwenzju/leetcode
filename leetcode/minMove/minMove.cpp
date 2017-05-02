#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//class Solution {
//public:
//	int minMoves(vector<int>& nums) {
//		if (nums.size() == 1) return 0;
//		if (nums.size() == 2) return abs(nums[0]-nums[1]);
//		sort(nums.begin(), nums.end());
//		int cnt = 0;
//		while (!isAllEqual(nums))
//		{
//			add1(nums);
//			cnt++;
//		}
//		return cnt;
//	}
//private:
//	bool isAllEqual(vector<int>& nums)
//	{
//		int n = nums[nums.size()-1];
//		for (int i = nums.size()-2; i >= 0; --i)
//		{
//			if (nums[i] < n) return false;
//			if (nums[i] > n){
//				while (nums[i] > n) --i;
//				int tmp = nums[i+1];
//				nums[i+1] = n;nums[nums.size()-1] = tmp;
//				return false;
//			}
//		}
//		return true;
//	}
//	void add1(vector<int>& nums)
//	{
//		for (int i = 0; i < nums.size()-1; ++i) nums[i]++;
//	}
//};

class Solution {
public:
	int minMoves(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		if (nums.size() == 2) return abs(nums[0]-nums[1]);
		sort(nums.begin(), nums.end());
		int cnt = 0;
		int max_idx = nums.size()-1;
		max_idx = cntMaxNums(nums, max_idx);
		if (max_idx == nums.size()-1) 
		{
			cnt += nums[max_idx] - nums[max_idx-1];
			addn(nums.begin(), nums.end()-1, cnt);
			max_idx = cntMaxNums(nums, max_idx);
		}

		while (max_idx > 0)
		{
			int tmp = nums.size() - max_idx;
			cnt += tmp;
			addn(nums.begin(), nums.begin()+max_idx, tmp);
			addn(nums.begin()+max_idx, nums.end(), tmp-1);
			max_idx = cntMaxNums(nums, max_idx);
		}
		
		return cnt;
	}
private:
	bool isAllEqual(vector<int>& nums)
	{
		int n = nums[nums.size()-1];
		for (int i = nums.size()-2; i >= 0; --i)
		{
			if (nums[i] < n) return false;
			if (nums[i] > n){
				while (nums[i] > n) --i;
				int tmp = nums[i+1];
				nums[i+1] = n;nums[nums.size()-1] = tmp;
				return false;
			}
		}
		return true;
	}
	void addn(vector<int>::iterator& b, vector<int>::iterator& e, int n)
	{
		for (; b < e; ++b) *b+=n;
	}
	int cntMaxNums(vector<int>& nums, int max_idx)
	{
		int m = nums[max_idx--];
		while (max_idx >= 0 && nums[max_idx] == m) max_idx--;
		return max_idx+1;
	}
};

int main()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);nums.push_back(2); nums.push_back(3);
	cout << s.minMoves(nums) << endl;
}