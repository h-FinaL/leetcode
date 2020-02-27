#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty() || word.empty())
			return false;

		for (int x = 0; x < board.size(); x++)
		{
			for (int y = 0; y < board[0].size(); y++)
			{
				if (exist(board, x, y, word, 0))
					return true;
			}
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, int x, int y, string& word, int i)
	{
		if (board[x][y] == 0 || board[x][y] != word[i])
			return false;
		if (i == word.size() - 1)
			return true;

		int result1 = false, result2 = false,  result3 = false, result4 = false;
		char c = board[x][y];
		board[x][y] = 0;
		if (x > 0)
			if (exist(board, x - 1, y, word, i + 1))
				return true;
		if (x < board.size() - 1)
			if (exist(board, x + 1, y, word, i + 1))
				return true;
		if (y > 0)
			if (exist(board, x, y - 1, word, i + 1))
				return true;
		if (y < board[0].size() - 1)
			if (exist(board, x, y + 1, word, i + 1))
				return true;

		board[x][y] = c;

		return false;
	}
};