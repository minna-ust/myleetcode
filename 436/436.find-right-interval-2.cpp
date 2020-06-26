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
        map<int, int> indexMap;

        for (int i = 0; i < intervals.size(); ++i)
        {
            indexMap.insert(pair<int, int>(intervals[i][0], i);
        }

        for (int i = 0; i < intervals.size(); ++i)
        {
            auto iter = indexMap.lower_bound(intervals[i][1]);
            if (iter == indexMap.end())
            {
                res[i] = -1;
            }
            else
            {
                res[i] = iter->second;
            }
        }

        return res;

    }
};
