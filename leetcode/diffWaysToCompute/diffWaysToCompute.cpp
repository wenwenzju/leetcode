#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		if (input.size() == 0) return vector<int>();
		int n = input.size();
		vector<int> numbers;
		string ops;
		for (int i = 0; i < n; ++i)
		{
			int j = i;
			while (i < n && isdigit(input[i])) i++;
			numbers.push_back(stoi(input.substr(j, i-j)));
			if (i < n)
				ops+=input[i];
		}
		vector<int> res;
		helper(numbers, ops, 0, res);
		return res;
	}
private:
	void helper(vector<int> numbers, string ops, int idx, vector<int>& res)
	{
		if (numbers.size() == 2 && ops.size()) {res.push_back(calculate(numbers[0], numbers[1], ops[0]));return ;}
		for (int i = idx; i < ops.size(); ++i)
		{
			vector<int> num = numbers;
			num[i] = calculate(numbers[i], numbers[i+1], ops[i]);
			num.erase(num.begin()+i+1);
			string op = ops;
			op.erase(i,1);
			helper(num, op, i==0?i:i-1, res);
		}
	}
	int calculate(int a, int b, char c)
	{
		switch(c)
		{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		}
		return a+b;
	}
};

int main()
{
	string s("2-1-1");
	Solution sol;
	vector<int> r = sol.diffWaysToCompute(s);
}