#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<string>& board) {
		if (board.size() !=9 || board[0].size() != 9) return false;
		vector<int> t(27,0);
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				char n = board[i][j];
				if (n == '.') continue;
				if (!isdigit(n) || n == '0') return false;
				n -= '0';
				int tmp = 1<<(n-1);
				if (t[i] & tmp != 0) return false;
				if (t[9+j] & tmp != 0) return false;
				if (t[18+3*(i/3)+j/3] & tmp != 0) return false;
				t[i] |= tmp; t[9+j] |= tmp; t[18+3*(i/3)+j/3] |= tmp;
			}
		}
		return true;
	}
};
//["..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."]
int main()
{
	Solution s;
	vector<string> board;
	board.push_back("..5.....6");
	board.push_back("....14...");
	board.push_back(".........");
	board.push_back(".....92..");
	board.push_back("5....2...");
	board.push_back(".......3.");
	board.push_back("...54....");
	board.push_back("3.....42.");
	board.push_back("...27.6..");
	bool fuck = s.isValidSudoku(board);
	return 1;
}