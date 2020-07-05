

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
     
        // map<int, vector<int>> treeMap;
        vector<vector<int>> adjaList;
        adjaList.resize(n);
        int index = 0;
        int root = 0;
        for (auto element : manager)
        {
            if (element != -1)
            {
                adjaList[element].push_back(index);
            }
            else
            {
                root = index;
            }
            index++;
        }

        return informTime[root] + recurBuild(root, adjaList, informTime);
    }


    int recurBuild(int root, vector<vector<int>> &adjaList, vector<int>&informTime)
    {
        vector<int> vec = adjaList[root];

        int t = 0;
        for (auto a : vec)
        {
            t = max(t, informTime[a] + recurBuild(a, adjaList, informTime));
        }
        return t;
    }


};
