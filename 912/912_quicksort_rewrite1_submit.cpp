class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void swap(int i, int j, std::vector<int> &nums)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    int partition(std::vector<int> &nums, int startIdx, int endIdx)
    {
        assert(startIdx <= endIdx);
        if (startIdx == endIdx)
            return startIdx;
        int pivot = nums[endIdx];
        int i = startIdx;
        int j = endIdx - 1;
        for (; i < j;)
        {
            if (nums[i] < pivot)
            {
                i++;
            } else {
                if (nums[j] >= pivot)
                {
                    j--;
                    continue;
                } else {
                    swap(i, j, nums);
                    // int tmp = nums[i];
                    // nums[i] = nums[j];
                    // nums[j] = tmp;
                    i++;
                    j--;
                    continue;
                }
            }
        }
        if (i == j)
        {
            if (nums[i] < nums[endIdx])
            {
                swap(i + 1, endIdx, nums);
                return i + 1;
            } else {
                swap(i, endIdx, nums);
                return i;
            }
        } else if (i > j) {
            swap(i, endIdx, nums);
            return i;
        }
        return startIdx;
    }

    void quickSort(std::vector<int> &nums, int startIdx, int endIdx)
    {
        if (startIdx >= endIdx)
        {
            return;
        }
        int mid = partition(nums, startIdx, endIdx);
        quickSort(nums, startIdx, mid - 1);
        quickSort(nums, mid + 1, endIdx);
    }

};
