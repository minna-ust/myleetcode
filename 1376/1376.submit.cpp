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
        buildTree(manager, informTime, res);
        return res;
    }


    // TreeNode* buildTree(vector<int> &manager, vector<int> &informTime, int &res)
    void buildTree(vector<int> &manager, vector<int> &informTime, int &res)
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
        // TreeNode *root = new TreeNode(treeMap[-1]);
        vector<int> allTime;
        // TreeNode *root =  recurBuild(treeMap[-1][0], treeMap, informTime[treeMap[-1][0]], informTime, allTime);

        recurBuild(treeMap[-1][0], treeMap, informTime[treeMap[-1][0]], informTime, allTime);

        // for (auto &v : allTime)
        // {
        //     cout << v << " \t ";
        // }
        res = *std::max_element(allTime.begin(), allTime.end());
        // return root;
        return;
    }


    // TreeNode* recurBuild(int root, map<int, vector<int>> &map, int time, vector<int>&informTime, vector<int> &allTime)
    void recurBuild(int root, map<int, vector<int>> &map, int time, vector<int>&informTime, vector<int> &allTime)
    {
        // std::cout << "z-----" << __FUNCTION__ << " " << __FILE__ << "::" << __LINE__ << " " <<  "root: " << root  << std::endl;
        // TreeNode *rootNode = new TreeNode(root);
        vector<int> vec = map[root];
        if (vec.size() == 0)
        {
            allTime.push_back(time);
            return;
            // return rootNode;
        }
        for (auto a : vec)
        {
            // rootNode->childs.push_back(recurBuild(a, map, informTime[a] + time, informTime, allTime));
            recurBuild(a, map, informTime[a] + time, informTime, allTime);
        }
        // return rootNode;
        return;
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
