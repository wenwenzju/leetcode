#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int n = data.size();
		for (int i = 0; i < n; ++i)
		{
			int bytes = howManyBytes(data[i]&0xff);
			if (bytes == 0) return false;
			if (bytes > n-i) return false;
			if (bytes == 1) continue;
			while (--bytes) if (!is10Head(data[++i]&0xff)) return false;
		}
		return true;
	}
private:
	int howManyBytes(int data)
	{
		if (data&0x80 == 0) return 1;
		if (data^0xC0<0x20) return 2;
		if (data^0xE0<0x10) return 3;
		if (data^0xF0<0x8) return 4;
		return 0;
	}
	bool is10Head(int data)
	{
		return data^0x80<0x40;
	}
};

int main()
{
	Solution s;
	vector<int> data; data.push_back(197);data.push_back(130);data.push_back(1);
	cout << s.validUtf8(data) << endl;
}