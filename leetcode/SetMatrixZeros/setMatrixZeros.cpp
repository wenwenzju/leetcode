#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size(); if (rows == 0) return;
		int cols = matrix[0].size();
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 1; c < cols; ++c)
			{
				if (matrix[r][c] == 0) {matrix[r][0] = 0; matrix[0][c] = 0;}
			}
		}
		for (int r = 0; r < rows; ++r)
		{
			for (int c = 0; c < cols; ++c)
			{
				if (matrix[r][0] == 0 || matrix[0][c] == 0) {matrix[r][c] = 0;}
			}
		}
	}
};

int main()
{
	vector<vector<int>> matrix;
	vector<int> tmp; 
	tmp.push_back(0); tmp.push_back(0); tmp.push_back(0);tmp.push_back(5);
	matrix.push_back(tmp);tmp.clear();
	tmp.push_back(4); tmp.push_back(3); tmp.push_back(1);tmp.push_back(4);
	matrix.push_back(tmp);tmp.clear();
	tmp.push_back(0); tmp.push_back(1); tmp.push_back(1);tmp.push_back(4);
	matrix.push_back(tmp);tmp.clear();
	tmp.push_back(1); tmp.push_back(2); tmp.push_back(1);tmp.push_back(3);
	matrix.push_back(tmp);tmp.clear();
	tmp.push_back(0); tmp.push_back(0); tmp.push_back(1);tmp.push_back(1);
	matrix.push_back(tmp);tmp.clear();
	Solution s;
	s.setZeroes(matrix);
}