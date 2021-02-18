第一种情况: nums1[k/2] = nums2[k/2];
nums1: 1, 3, 6, 7, 9;
nums2: 2, 4, 6, 8, 10 ---> 合并后第5大的数
    将会是6;
第二种情况: nums1[k/2] < nums2[k/2];
nums1: 1, 3, 5, 7, 9;
nums2: 2, 4, 6, 8, 10;
1, 2, 3, 4, 5, 6, 7, 8, 9, 10;
-----------------------
总数为奇数:
1, 2, 3, 4, 5, 6, 7, 8, 10;
-----------------------
nums1: 1, 2;
nums2: 1, 3, 4, 5, 6, 7;
假如找第6大的,
-----------------------
nums1: 1, 9;
nums2: 1, 3, 4, 5, 6, 7;
-----------------------

double getMedianOfTwoSortedArrays(std::vector<int> &nums1,
    std::vector<int> &nums2)
{
    int size1 = nums1.size();
    int size2 = nums2.size();
    int left = (size1 + size2 + 1) / 2;
    int right = (size1 + size2 + 2) / 2;

    return 0.5 * getKth(nums1, 0, size1 - 1, nums2, 0, size2 - 1, left) +
        0.5 * getKth(nums1, 0, size1 - 1, nums2, 0, size2 - 1, right);
}

int getKth(std::vector<int> &nums1, int start1, int end1,
    std::vector<int> &nums2, int start2, int end2, int k)
{
    if (k == 1)
    {
        return nums1[start1] < nums2[start2] ? nums1[
    if (nums1[start1 + k / 2 - 1] == nums2[start2 + k / 2 - 1])
    {
        return getKth(nums1, k / 2, end1, nums2, start2, end2, (k - k / 2) / 2);
    }
