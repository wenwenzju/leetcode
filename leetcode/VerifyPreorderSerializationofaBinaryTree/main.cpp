#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		int n = preorder.size();
		if (n <= 0) return false;
		if (n == 1) return preorder[0] == '#';
		if (preorder[0] == '#') return false;

		bool next = false;
		stack<int> st; st.push(1);
		int i = 0;
		skip(preorder, i, n);
		next = hasNext(preorder, i);
		while (i < n && (!st.empty() || next))
		{
			if (next)
			{
				st.push(1);
				skip(preorder, i, n);
				next = hasNext(preorder, i);
			}
			else
			{
				st.pop();
				skip(preorder, i, n);
				next = hasNext(preorder, i);
			}
		}
		return i < n;
	}
private:
	void skip(string& preorder, int& i, int n)
	{
		while (i < n && preorder[i++] != ',');
	}
	bool hasNext(string& p, int i)
	{
		return i< p.size() && p[i] != '#';
	}
};

int main()
{
	string s("9,3,4,#,#,1,#,#,2,#,6,#,#");
	Solution sol;
	sol.isValidSerialization(s);
}