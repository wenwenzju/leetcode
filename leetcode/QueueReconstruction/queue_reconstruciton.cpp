#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		int n = people.size();
		if (n <= 1) return people;
		sort(people.begin(), people.end(), [](pair<int,int> a, pair<int,int> b)->bool{return a.first < b.first;});
		vector<pair<int,int>> res(n);
		vector<int> flags(n, false);
		int cur_height = people[0].first;
		for (int i = 0; i < n; ++i)
		{
			//if (people[i].first == cur_height)
			if (i == 0) {res[people[i].second] = people[i];flags[people[i].second] = 1;}
			else
			{
				int idx = -1, j = 0;
				for (; j < n && idx < people[i].second; ++j)
				{
					if (!flags[j] || res[j].first == people[i].first) ++idx;
				}
				//j = j < n?j:j-1;
				res[j-1] = people[i];
				flags[j-1] = 1;
			}
			cur_height = people[i].first;
		}
		return res;
	}
};

int main()
{
	vector<pair<int, int>> people;
	people.push_back(pair<int,int>(7,0));
	people.push_back(pair<int,int>(4,4));
	people.push_back(pair<int,int>(7,1));
	people.push_back(pair<int,int>(5,0));
	people.push_back(pair<int,int>(6,1));
	people.push_back(pair<int,int>(5,2));
	Solution s;
	vector<pair<int,int>> res = s.reconstructQueue(people);
	return 0;
}