#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> data;
	int d;
	while(cin >> d) data.push_back(d);
	int n = data.size();
	string s;
	for (int i = 0; i < n; ++i) s+=to_string((long long)data[i]);
	int maxDigit;
	for (int i = 0; i < s.size(); ++i) if (maxDigit < s[i]-'0') maxDigit = s[i]-'0';
	if (maxDigit == 0) cout << 0 << endl;
	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		string tmp = to_string((long long)data[i]);
		for (int j = 0; j < tmp.size(); ++j)
		{
			if (tmp[j]-'0' != maxDigit) continue;
			else
			{
				string str = tmp.substr(j);
				for (int k = 0; k < n; ++k)
				{
					int idx = (i+k+1)%n;

				}
			}
		}
	}
}