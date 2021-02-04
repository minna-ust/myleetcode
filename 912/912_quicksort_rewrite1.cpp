#include "../stdcom.hpp"


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
    }
    if (i > j)
    {
        swap(i, endIdx, nums);
        return i;
    }
}

void quickSort(std::vector<int> &nums, int startIdx, int endIdx)
{
    int mid = partition(nums, startIdx, endIdx);
    quickSort(nums, startIdx, mid - 1);
    quickSort(nums, mid + 1, endIdx);
}


--------------------------------------------------
            1, 2, 3, 2 ---> 1, 2, 1, 4, 2 ---> 1, 2, 1, 0, 4, 2 ---> 1, 2, 1, 0, 0, 4, 2 ---> 1, 2, 1, 5, 0, 0, 4, 2
            1, 2, 1, 5, 0, 0, 4, 2 --->
            1, 0, 1, 5, 0, 2, 4, 2 --->
            1, 0, 1, 0, 5, 2, 4, 2 --->
            1, 0, 1, 0, 2, 2, 4, 5 ,
            --------------------------------------------------
            1, 2, 1, 5, 0, 0, 0, 4, 2 --->
            1, 0, 1, 5, 0, 0, 2, 4, 2 --->
            1, 0, 1, 0, 0, 5, 2, 4, 2 --->
            1, 0, 1, 0, 0, 5, 2, 4, 2 --->
            1, 0, 1, 0, 0, 2, 2, 4, 5
            --------------------------------------------------
    1, 2, 1, 5, 9, 0, 0, 4, 2 --->
    1, 0, 1, 5, 9, 0, 2, 4, 2 --->
    1, 0, 1, 0, 9, 5, 2, 4, 2 --->
    1, 0, 1, 0, 9, 5, 2, 4, 2 --->
