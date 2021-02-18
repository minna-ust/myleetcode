2, 1, 1, 3, 5, 4 --->
    1, 1, 2, 3, 5, 4 --->
    1, 1, 2, 3, 5, 4 --->
    1, 1, 2, 3, 5, 4 --->
    1, 1, 2, 3, 5, 4 --->
    1, 1, 2, 3, 4, 5

void selectSort(std::vector<int> &nums)
{
    for (int i = 0; i <= nums.size() - 1; ++i)
    {
        int min = nums[i];
        int minIdx = i;
        for (int j = i + 1; j <= nums.size() - 1; ++j)
        {
            if (nums[j] < min)
            {
                min = nums[j];
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int tmp = nums[i];
            nums[i] = nums[minIdx];
            nums[minIdx] = tmp;
        }
    }
}
