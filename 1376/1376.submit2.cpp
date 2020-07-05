/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
#include "stdcom.hpp"
// struct TreeNode {
//     int _idx;
//     vector<TreeNode *> childs;
//     TreeNode(int idx): _idx(idx){};
//     ~TreeNode(){};
// };

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        return buildTree(manager, informTime);
    }



    // TreeNode* buildTree(vector<int> &manager, vector<int> &informTime, int &res)
    int buildTree(vector<int> &manager, vector<int> &informTime)
    {
        map<int, vector<int>> treeMap;
        int index = 0;
        for (auto element : manager)
        {
            if (treeMap.count(element))
            {
                treeMap[element].push_back(index);
            }
            else
            {
                treeMap.insert(pair<int, vector<int>>(element, vector<int>{index}));
            }
            index++;
        }

        for (auto &a : treeMap)
        {
            cout << a.first << " \t " << treeMap[a.first][0] << endl;
        }
        vector<int> allTime;

        return recurBuild(treeMap[-1][0], treeMap, informTime, allTime);
    }


    int recurBuild(int root, map<int, vector<int>> &map, vector<int>&informTime, vector<int> &allTime)
    {
        vector<int> vec = map[root];

        int t = 0;
        for (auto a : vec)
        {
            t = max(t, informTime[a] + recurBuild(a, map, informTime, allTime));
        }
        return t;
    }

};
// @lc code=end

int main(int argc, char** argv)
{
    vector<int> manager{3, 3, -1, 2};
    vector<int> informTime{0, 0, 162, 914};
    Solution().numOfMinutes(4, 2, manager, informTime);
    return 0;
}
