/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

/*
  TODO: 花的时间太长,待改进
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
        {
            return 0;
        }
        //std::cout << grid.size() << "\t" << grid[0].size() << std::endl;

        vector<vector<char>> res;
        vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                //std::cout << i << "\t" << j << std::endl;
                vector<char> island;
                dfs(i, j, grid, flag, island);
                if (!island.empty())
                {
                    res.push_back(island);
                }
            }
        }
        return res.size();
    }

    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &flag, vector<char> &island)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return;
        }
        if (flag[i][j] == true || grid[i][j] == '0')
        {
            return;
        }
        //std::cout << "dfs " << i << "\t" << j << std::endl;
        island.push_back(grid[i][j]);
        flag[i][j] = true;
        dfs(i + 1, j, grid, flag, island);
        dfs(i, j + 1, grid, flag, island);
        dfs(i - 1, j, grid, flag, island);
        dfs(i, j - 1, grid, flag, island);
    }
};
// @lc code=end
