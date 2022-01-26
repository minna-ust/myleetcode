bool canJump(vector<int>& nums)
{
    int sz = nums.size();
    if (sz == 0)
        return false;
    vector<bool> abilities(sz, false);
    abilities[sz - 1] = true;
    for (int i = sz - 2; i >= 0; i--)
    {
        int val = nums[i];
        if (val == 0)
        {
            abilities[i] = false;
        }
        else
        {
            for (int j = 1; j <= val; j++)
            {
                if (i + j >= sz - 1)
                {
                    abilities[i] = true;
                    break;
                }
                abilities[i] |= abilities[i+j];
                if (abilities[i] == true)
                    break;
            }
        }
    }
    return abilities[0];
}
