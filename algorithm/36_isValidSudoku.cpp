#include <vector>

/*
36. 有效的数独
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。

*/

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9)
        {
            return false;
        }

        int flag[9] = {0};
        for (int i = 0; i < 9; i++)
        {
            memset(flag, 0, sizeof(flag));
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                int p = board[i][j] - '1';
                if (flag[p] == 1)
                    return false;
                else
                    flag[p] = 1;
            }
            memset(flag, 0, sizeof(flag));
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                int p = board[j][i] - '1';
                if (flag[p] == 1)
                    return false;
                else
                    flag[p] = 1;
            }

            memset(flag, 0, sizeof(flag));
            int x_b = i / 3 * 3;
            int y_b = i % 3 * 3;
            for (int j = 0; j < 9; j++)
            {
                int x = x_b + j / 3;
                int y = y_b + j % 3;
                if (board[x][y] == '.')
                    continue;
                int p = board[x][y] - '1';
                if (flag[p] == 1)
                    return false;
                else
                    flag[p] = 1;
            }
        }
        return true;
    }
};