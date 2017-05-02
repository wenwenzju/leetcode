#include <vector>
#include <map>
#include <hash_map>
#include <iostream>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		if (points.size() <= 2) return 0;
		int cnt = 0;
		int len = points.size();
		vector<vector<double>> dis(len,vector<double>(len,0.));
		for (int i = 0; i < len; ++i)
		{
			for (int j = i; j < len; ++j)
			{
				dis[i][j] = distance(points[i], points[j]);
				dis[j][i] = dis[i][j];
			}
		}

		for (int i = 0; i < len; ++i)
		{
			hash_map<double,int> sameDisCnt;
			for (int j = 0; j < len; ++j)
			{
				if (sameDisCnt.find(dis[i][j]) == sameDisCnt.end()) {sameDisCnt[dis[i][j]] = 1;continue;}
				sameDisCnt[dis[i][j]]++;
			}
			hash_map<double,int>::iterator b = sameDisCnt.begin(), e = sameDisCnt.end();
			for (; b != e; ++b)
			{
				if (b->second == 1) continue;
				cnt += b->second*(b->second-1);
			}
		}
		return cnt;
	}
private:
	inline double distance(pair<int,int>& p1, pair<int,int>& p2)
	{
		double x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
		return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	}
};

int main()
{
	vector<pair<int,int>> points;
	points.push_back(pair<int,int>(0,0));
	points.push_back(pair<int,int>(1,0));
	points.push_back(pair<int,int>(2,0));
	Solution s;
	cout << s.numberOfBoomerangs(points) << endl;
}