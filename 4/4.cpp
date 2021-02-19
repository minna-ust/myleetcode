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
假如找第6大的, 比较的是2与4; 直接舍弃nums1中的1, 2; 返回nums2中的第(6 - 2)大元素.
-----------------------
nums1: 1, 9;
nums2: 1, 3, 4, 5, 6, 7;
如果找第5大的, 分别比较nums1和nums2第5/2 = 2大的数，也就是9和3, 因为9 > 3,
    所以第5大的数一定不在nums2的前2个数中，nums2将会变为4, 5, 6, 7,
    此时只需要找第5 - 2 = 3大的数，继续找nums1 和 nums2中第3/2 = 1大的数，也就是
    1 和 4， 同理去掉1, nums1变为9, nums2为4, 5, 6, 7, 接下来找第(3 - 1 = 2)大的数，
    需要找nums1和nums2中(2/2 = 1)大的数，也就是9和4，nums2将变为5, 6, 7， nums1为9,
    继续找第(2 - 1) = 1大的数, 比较5 和 9返回最小的那个就可以了(也就是5是第5大的)
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
