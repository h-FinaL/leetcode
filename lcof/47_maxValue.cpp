#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<int> v(grid[0].size(), 0);
        v[0] = grid[0][0];

        for (int y = 1; y < grid[0].size(); y++)
            v[y] = grid[0][y] + v[y - 1];

        for (int x = 1; x < grid.size(); x++)
        {
            v[0] = v[0] + grid[x][0];
            for (int y = 1; y < grid[0].size(); y++)
            {
                int max = v[y - 1] > v[y] ? v[y - 1] : v[y];
                v[y] = max + grid[x][y];
            }
        }

        return v[v.size() - 1];
    }
};