nums: 1, 1, 2, 2, 2, 4, 4, 5, 6;
用双指针法;
1, 1, 2, 2, 2, 4, 4, 5, 6 --->;
1, 2, 2, 2, 2, 4, 4, 5, 6 --->;
1, 2, 4, 2, 2, 4, 4, 5, 6 --->;
1, 2, 4, 5, 2, 4, 4, 5, 6 --->;
1, 2, 4, 5, 6, 4, 4, 5, 6 ---> ;

--------------------------------------
下面我们讲一下leetcode第26题: 去除有序数组中的重复项
1, 1, 2, 2, 2, 4, 4, 5, 6 --->;
1, 1, 2, 2, 2, 4, 4, 5, 6 ---> ;
1, 2, 2, 2, 2, 4, 4, 5, 6 ---> ;
1, 2, 2, 2, 2, 4, 4, 5, 6 ---> ;
1, 2, 4, 2, 2, 4, 4, 5, 6 --->;
1, 2, 4, 5, 2, 4, 4, 5, 6 ---> ;
1, 2, 4, 5, 6, 4, 4, 5, 6 ---> ;
int rmDuplicateOfSortedArray(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int i = 0;
    int j = 0;
    for (; j <= nums.size() - 1;)
    {
        if (nums[j] == nums[i])
        {
            j++;
        }
        else
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i + 1;
}
