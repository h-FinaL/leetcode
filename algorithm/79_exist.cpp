#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty() || word.empty()) return false;
		vector<vector<char>> vv(board.size(), vector<char>(board[0].size(), 0));
		bool result = false;
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board[0].size(); y++)
			{
				if (board[x][y] == word[0])
					result = exist(board, vv, x, y, word, 0);
				if (result == true) return result;
			}
		}

		return result;
	}

	bool exist(vector<vector<char>>& board, vector<vector<char>>& vv, int x, int y, string& word, int i) {
		if (board[x][y] != word[i] || vv[x][y] == 1) return false;
		if (i == word.size() - 1) return true;
		vv[x][y] = 1;
		bool b = false;
		if (x > 0) 
			b = exist(board, vv, x - 1, y, word, i + 1);
		if (x < board.size() - 1 && !b)
			b = exist(board, vv, x + 1, y, word, i + 1);
		if (y > 0 && !b) 
			b = exist(board, vv, x, y - 1, word, i + 1);
		if (y < board[0].size() - 1 && !b)
			b = exist(board, vv, x, y + 1, word, i + 1);
		vv[x][y] = 0;
		return b;
	}
};