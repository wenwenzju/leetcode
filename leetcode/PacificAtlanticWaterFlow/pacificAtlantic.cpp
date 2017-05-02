#include <vector>
using namespace std;

class Solution {
private: int rows, cols;
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<pair<int,int>> res;
		rows = matrix.size(); if (rows == 0) return res;
		cols = matrix[0].size(); if (cols == 0) return res;
		vector<vector<int>> pacs(rows, vector<int>(cols, -1)), atls(rows, vector<int>(cols, -1));
		for (int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
				if (pacs[i][j] == -1) pacific(matrix, i, j, pacs);
		}
		for (int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
				if (atls[i][j] == -1) atlantic(matrix, i, j, atls);
		}
		for (int i = 0; i < rows; ++i)
		{
			for(int j = 0; j < cols; ++j)
				if (pacs[i][j] == 1 && atls[i][j] == 1) res.push_back(pair<int,int>(i, j));
		}
		return res;
	}
private:
	int pacific(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& pacs)
	{
		if (pacs[i][j] != -1) return pacs[i][j];
		if (j == 0 || i == 0) {pacs[i][j] = 1; return 1;}
		int a = 0, b = 0, c = 0, d = 0;
		int curHei = matrix[i][j];
		if (i > 0 && matrix[i-1][j] <= curHei) {pacs[i-1][j] = pacific(matrix, i-1, j, pacs);a=pacs[i-1][j];}
		if (a == 1) {pacs[i][j] = a; return a;}
		if (i < rows-1 && matrix[i+1][j] <= curHei) {pacs[i+1][j] = pacific(matrix, i+1, j, pacs);b=pacs[i+1][j];}
		if (b == 1) {pacs[i][j] = b; return b;}
		if (j > 0 && matrix[i][j-1] <= curHei) {pacs[i][j-1] = pacific(matrix, i, j-1, pacs);c=pacs[i][j-1];}
		if (c == 1) {pacs[i][j] = c; return c;}
		if (j < cols-1 && matrix[i][j+1] <= curHei) {pacs[i][j+1] = pacific(matrix, i, j+1, pacs);d=pacs[i][j+1];}
		if (d == 1) {pacs[i][j] = d; return d;}
		pacs[i][j] = 0;
		return pacs[i][j];
	}
	int atlantic(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& pacs)
	{
		if (pacs[i][j] != -1) return pacs[i][j];
		if (j == cols-1 || i == rows-1) {pacs[i][j] = 1; return 1;}
		int a = 0, b = 0, c = 0, d = 0;
		int curHei = matrix[i][j];
		if (i > 0 && matrix[i-1][j] <= curHei) {pacs[i-1][j] = pacific(matrix, i-1, j, pacs);a=pacs[i-1][j];}
		if (a == 1) {pacs[i][j] = a; return a;}
		if (i < rows-1 && matrix[i+1][j] <= curHei) {pacs[i+1][j] = pacific(matrix, i+1, j, pacs);b=pacs[i+1][j];}
		if (b == 1) {pacs[i][j] = b; return b;}
		if (j > 0 && matrix[i][j-1] <= curHei) {pacs[i][j-1] = pacific(matrix, i, j-1, pacs);c=pacs[i][j-1];}
		if (c == 1) {pacs[i][j] = c; return c;}
		if (j < cols-1 && matrix[i][j+1] <= curHei) {pacs[i][j+1] = pacific(matrix, i, j+1, pacs);d=pacs[i][j+1];}
		if (d == 1) {pacs[i][j] = d; return d;}
		pacs[i][j] = 0;
		if (pacs[i][j] > 1) pacs[i][j] = 1;
		return pacs[i][j];
	}
};

int main()
{
	vector<vector<int>> matrix;
	vector<int> tmp; 
	tmp.push_back(1);tmp.push_back(2);tmp.push_back(2);tmp.push_back(3);tmp.push_back(5);matrix.push_back(tmp); tmp.clear();
	tmp.push_back(3);tmp.push_back(2);tmp.push_back(3);tmp.push_back(4);tmp.push_back(4);matrix.push_back(tmp); tmp.clear();
	tmp.push_back(2);tmp.push_back(4);tmp.push_back(5);tmp.push_back(3);tmp.push_back(1);matrix.push_back(tmp); tmp.clear();
	tmp.push_back(6);tmp.push_back(7);tmp.push_back(1);tmp.push_back(4);tmp.push_back(5);matrix.push_back(tmp); tmp.clear();
	tmp.push_back(5);tmp.push_back(1);tmp.push_back(1);tmp.push_back(2);tmp.push_back(4);matrix.push_back(tmp); tmp.clear();
	Solution s;
	vector<pair<int,int>> res = s.pacificAtlantic(matrix);
}