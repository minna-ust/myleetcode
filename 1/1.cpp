nums: 2, 7, 11, 13;
target: 9

map,保存数和它的index;
基本思想, 遍历数组，对某个数，求补,判断这个补数是否在map中，如果在，就说明找到了,
    有两种逻辑:
    1. 先将该数放入map中，但这时处理不了nums为[3, 3]的情况;
2.如下面代码所示，先求补数，判断补数是否在map中，再将该数放入map中

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::map<int, int> mValueIndex;
    for (int i = 0; i <= nums.size() - 1; ++i)
    {
        int complement = target - nums[i];
        if (mValueIndex.find(complement) != mValueIndex.end())
        {
            return std::vector<int>{i, mValueIndex[complement]};
        }

        mValueIndex[nums[i]] = i;
    }

    return {};
}
