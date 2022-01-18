// 1 2 3 ---> 1 2 3 4 (插入4， 中位数需后移一位)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            DualPriorityQueue.insert(nums[i]);
            if ( i >= k)
            {
                DualPriorityQueue.erase(nums[i-k]);
                res.push_back(DualPriorityQueue.getMedian());
            }
        }
        return res;
    }
};
