#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int house_num = houses.size(), heater_num = heaters.size();
		if (house_num <= 0 || heater_num <= 0) return 0;
		vector<int> house_heated0(house_num,0),house_heated1(house_num,0);
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int minr = 0, maxr = min(max(abs(houses[0]-heaters[0]),abs(houses[house_num-1]-heaters[0])), max(abs(houses[0]-heaters[heater_num-1]),abs(houses[house_num-1]-heaters[heater_num-1])));
		int radius = maxr;
		heat_house(houses, heaters, minr, house_heated0);
		heat_house(houses, heaters, maxr, house_heated1);
		while (1)
		{
			if (all1(house_heated0)) return minr;
			if (all1(house_heated1)&&maxr-minr == 1) return maxr;
			int m = (minr+maxr)/2;
			vector<int> hh = house_heated0;
			heat_house(houses, heaters, m, hh);
			if (all1(hh))
			{
				maxr = m;
				house_heated1 = hh;
			}
			else
			{
				minr = m;
				house_heated0 = hh;
			}
		}
	}
private:
	void heat_house(vector<int>& houses, vector<int>& heaters, int radius, vector<int>& house_heated)
	{
		for (int i = 0; i < houses.size(); ++i)
		{
			if (house_heated[i]) continue;
			int lh = 0, uh = heaters.size() - 1;
			while (1)
			{
				if (houses[i]<heaters[lh]-radius) break;
				if (houses[i]>heaters[uh]+radius) break;
				if (houses[i]>=heaters[lh]-radius&&houses[i]<=heaters[lh]+radius){house_heated[i]=1;break;}
				if (houses[i]>=heaters[uh]-radius&&houses[i]<=heaters[uh]+radius){house_heated[i]=1;break;}
				if (uh-lh == 1) break;
				int m = (lh+uh)/2;
				if (houses[i]<=heaters[m]) uh = m;
				else if (houses[i]>heaters[m]) lh = m;
				if (lh >= uh) break;
			}
		}
	}
	bool all1(vector<int>& house_heated)
	{
		vector<int>::iterator b = house_heated.begin(), e = house_heated.end();
		bool res = true;
		for (;b!=e&&res;++b) res &= *b;
		return res;
	}
};

int main()
{
	Solution s;
	int ho[] = {1,2,3,4}, he[] = {1,4};
	int test[52];
	vector<int> houses, heaters;
	houses.push_back(1);houses.push_back(2);houses.push_back(3);houses.push_back(4);
	heaters.push_back(1);heaters.push_back(4);
	cout << s.findRadius(houses, heaters) << endl;
}