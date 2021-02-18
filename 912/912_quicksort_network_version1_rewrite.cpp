2, 1, 3, 5, 1, 4  ---> (x = 2)
    1, 1, 3, 5, 1, 4 --->
    1, 1, 3, 5, 3, 4 --->
    1, 1, 2, 5, 3, 4
void quickSort(std::vector<int> nums, int l, int r)
{
    if (l < r)
    {
        int i = l;
        int j = r;
        int x = nums[l];
        while ( i < j )
        {
            while (i < j && nums[j] >= x)
                j--;
            if (i < j)
                nums[i++] = nums[j];
            while (i < j && nums[i] < x)
                i++;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = x;
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
}
