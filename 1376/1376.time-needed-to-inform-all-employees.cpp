/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start

#include "stdcom.hpp"
struct TreeNode {
    int _idx;
    vector<TreeNode *> childs;
    TreeNode(int idx): _idx(idx){};
    ~TreeNode(){};
}

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        buildTree(manager);

    }

    TreeNode* buildTree(vector<int> &manager)
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
            cout << a << " \t " << treeMap[a][0] << endl;
        }
        // TreeNode *root = new TreeNode(treeMap[-1]);
        TreeNode *root =  recurBuild(treeMap[-1], treeMap);
        return root;
    }
    TreeNode* recurBuild(int root, map<int, vector<int>> &map)
    {
        std::cout << "z-----" << __FUNCTION__ << " " << __FILE__ << "::" << __LINE__ << " " <<  "root: " << root  << std::endl;
        TreeNode *root = new TreeNode(root);
        vector<int> vec = map[root];
        for (auto a : vec)
        {
            root->childs.push_back(recurBuild(a, map));
        }
        return root;
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
