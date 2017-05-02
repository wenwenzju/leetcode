#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if(numCourses <= 1 || prerequisites.empty()) return true;
		sort(prerequisites.begin(), prerequisites.end(), [](pair<int,int>& a, pair<int,int>& b)->bool{return a.second < b.second;});
		vector<int> indegree(numCourses, 0);
		int n = prerequisites.size();
		vector<int> idxes(numCourses, -1);
		for (int i = 0; i < n; ++i) {++indegree[prerequisites[i].first];if (idxes[prerequisites[i].second] == -1) idxes[prerequisites[i].second] = i;}
		stack<int> s;
		for (int i = 0; i < numCourses; ++i) if (indegree[i] == 0) s.push(i);
		int cnt = 0;
		while (!s.empty())
		{
			int tmp = s.top(); s.pop();
			++cnt;
			int i = idxes[tmp];
			if (i == -1) continue;
			for (int course = prerequisites[i].second; i < n; ++i)
			{
				if (prerequisites[i].second != course) break;
				if (--indegree[prerequisites[i].first] == 0) s.push(prerequisites[i].first);
			}
		}
		return cnt == numCourses;
	}
};

int main()
{
	int numCourses, edges;
	cin >> numCourses >> edges;
	vector<pair<int,int>> prerequisites;
	for (int i = 0; i < edges; ++i)
	{
		int c1,c2;
		cin >> c1 >> c2;
		prerequisites.push_back(pair<int,int>(c1, c2));
	}
	Solution s;
	s.canFinish(numCourses, prerequisites);
}