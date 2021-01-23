#include "../stdcom.hpp"

int partition(std::vector<int> &nums, int startIdx, int endIdx)
{
    assert(startIdx <= endIdx);
    if (startIdx == endIdx)
        return startIdx;
    int pivot = nums[endIdx];
    int i = startIdx;
    int j = endIdx - 1;
    for (; i <= j;)
    {
         1, 2, 3, 2 ---> 1, 2, 1, 4, 2 ---> 1, 2, 1, 0, 4, 2 ---> 1, 2, 1, 0, 0, 4, 2 ---> 1, 2, 1, 5, 0, 0, 4, 2
         --- 1, 2, 1, 5, 0, 0, 4, 2 --->
             1, 0, 1, 5, 0, 2, 4, 2 --->

        if (nums[i] <

void quickSort(std::vector<int> &nums, int startIdx, int endIdx)
{
    int mid = partition(nums, startIdx, endIdx);
    quickSort(nums, startIdx, mid - 1);
    quickSort(nums, mid + 1, endIdx);
}
