#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		if (s.size()==0) return s;
		vector<int> idxes;
		for (int i = 0; i < s.size(); ++i) if (isALetterVowel(s[i])) idxes.push_back(i);
		if (idxes.size()==0||idxes.size()==1) return s;
		string ss = s;
		for (int i = 0, j = idxes.size()-1;i<j;++i,--j)
		{
			char tmp = ss[idxes[i]];
			ss[idxes[i]] = ss[idxes[j]];
			ss[idxes[j]] = tmp;
		}
		return ss;
	}
private:
	inline bool isALetterVowel(char c)
	{
		return (c=='a'||c=='A'|| c=='e'||c=='E'|| c=='i'||c=='I'|| c=='o'||c=='O'|| c=='u'||c=='U');
	}
};

int main()
{
	Solution s;
	string str("hello");
	string res = s.reverseVowels(str);
	cout << res.c_str() << endl;
}