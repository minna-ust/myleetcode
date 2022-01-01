class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
    }

    int pick(int target) {
        int count = 1;
        int res = -1;
        for (int i = 0; i < nums_.size(); ++i)
        {
            if (nums_[i] == target)
            {
                if (rand() % count == 0)
                {
                    res = i;
                }
                count++;
            }
        }
        return res;
    }
};
