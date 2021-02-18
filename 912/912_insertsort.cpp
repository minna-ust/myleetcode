2, 1, 3, 5, 4 ---> tmp = 1;
2, 2, 3, 5, 4 --->
    1, 2, 3, 5, 4 --->
    1, 2, 3, 5, 4 --->
    1, 2, 3, 5, 4 --->
    1, 2, 3, 5, 4 --->
    1, 2, 3, 5, 5 --->
    1, 2, 3, 4, 5


void insertSort(std::vector<int> &nums)
{
    for (int i = 1; i <= nums.size() - 1; ++i)
    {
        int tmp = nums[i];
        int j = i;
        while (j > 0 && nums[j - 1] > tmp)
        {
            nums[j] = nums[j - 1];
            j--;
        }
        if (j != i)
        {
            nums[j] = tmp;
        }
    }
}
