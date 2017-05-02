#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string toHex(int num) {
		if (num==0)return "0";
		int tmp = num;
		string res(8,'0');
		int cnt = 7;
		while (tmp)
		{
			int b4=tmp&15;
			if (b4<10) res[cnt] = '0'+b4;
			else res[cnt] = 'a'+b4-10;
			cnt--;
			tmp = tmp >> 4;
		}
		return res.substr(cnt+1);
	}
};

void Show(short n) {
	short i;
	printf("%d(",n);
	for(i = 0; i < 16; ++i)
		printf("%d",(n & (1 << (15 - i))) >> (15 - i));
	printf(")B\n");
}

int main()
{
	Solution s;
	short tmp = 0x800f;
	Show(tmp>>4);
}