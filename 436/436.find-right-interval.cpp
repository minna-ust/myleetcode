/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */


/*
 问题: TLE time limit exceeded
 */


// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return vector<int>();
        }
        if (intervals.size() == 1)
        {
            return vector<int>(1, -1);
        }
        vector<int> res = vector<int>(intervals.size(), -1);
        for (int i = 1; i < intervals.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (res[j] == -1 && intervals[j][1] <= intervals[i][0])
                {
                    res[j] = i;
                }
                if (res[j] != -1 && intervals[j][1] <= intervals[i][0])
                {
                    if (intervals[res[j]][0] > intervals[i][0])
                    {
                        res[j] = i;
                    }
                }
                if (res[i] == -1 && intervals[j][0] >= intervals[i][1])
                {
                    res[i] = j;
                }
                if (res[i] != -1 && intervals[j][0] >= intervals[i][1])
                {
                    if (intervals[res[i]][0] > intervals[j][0])
                    {
                        res[i] = j;
                    }
                }
            }
        }
        return res;

    }
};
// @lc code=end
