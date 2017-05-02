#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& nums, int l, int r)//1.select pivot; 2.i is boundary of part smaller and part bigger, l is boundary of part bigger and part not partition; 3.swap nums[i] and nums[j]
{
	int tmp = l+rand()%(r-l+1);
	swap(nums[tmp], nums[r]);
	int pivot = nums[r];
	int i = l-1;
	for (;l < r; ++l)
	{
		if (nums[l] <= pivot)
		{
			i++;
			swap(nums[i], nums[l]);
		}
	}
	swap(nums[i+1], nums[r]);
	return i+1;
}
void quick_sort_range(vector<int>& nums, int l, int r)//1.partition first; 2. sort each partition
{
	if (l < r)
	{
		int p = partition(nums, l, r);
		quick_sort_range(nums, l, p-1);
		quick_sort_range(nums, p+1, r);
	}
}
void quick_sort(vector<int>& nums)
{
	quick_sort_range(nums, 0, nums.size()-1);
}

#define MAX_VAL 20
#define MAX_NUM 5
#define PRINT_VECTOR(v) for_each(v.begin(), v.end(), [](int i){cout << i << " ";});cout << endl;
int main()
{
	vector<int> nums;
	for (int i = 0; i < MAX_NUM; ++i) nums.push_back(rand()%MAX_VAL+1);
	PRINT_VECTOR(nums);

	quick_sort(nums);
	PRINT_VECTOR(nums);

	return 1;
}