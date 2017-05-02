// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// 
// class Solution {
// public:
// 	vector<int> topKFrequent(vector<int>& nums, int k) {
// 		unordered_map<int,int> map;
// 		int n = nums.size();
// 		for (int i = 0; i < n; ++i) map[nums[i]]++;
// 		vector<float> bucket(n+1, 0.1);
// 		unordered_map<int,int>::iterator b = map.begin(), e = map.end();
// 		for (; b!=e; ++b)
// 		{
// 			bucket[b->second] = b->first;
// 		}
// 		vector<int> res;
// 		for (int i = n; i >= 0 && k > 0; --i)
// 		{
// 			if (bucket[i] != 0.1f) 
// 			{res.push_back((int)bucket[i]);k--;}
// 		}
// 		return res;
// 	}
// };
// 
// int main()
// {
// 	vector<int> nums;
// 	nums.push_back(1);nums.push_back(1);nums.push_back(1);nums.push_back(2);nums.push_back(2);nums.push_back(3);
// 	Solution s;
// 	vector<int> res = s.topKFrequent(nums, 2);
// }

int main()
{
	int a = 1, b = 2;
	double c = a/b*1.;
}