bool canJump(vector<int>& nums)
{
    int sz = nums.size();
    if (sz == 0)
        return false;
    int right_most = 0;
    for (int i = 0; i < sz; i++)
    {
        if (i > right_most)
        {
            return false;
        }
        right_most = std::max(right_most, i + nums[i]);
    }

    return true;
}
