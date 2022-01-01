int maxArea(vector<int>& height) {
    int size = height.size();
    if (size < 2)
    {
        return 0;
    }
    vector<int> vec(size, 0);
    vector<vector<int>> dp(size, vec);
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j + i < size; ++j)
        {
            if (i == 1)
            {
                dp[j][j + i] = std::min(height[j], height[j+i]) * i;
            }
            else
            {
                dp[j][j+i] = std::max(dp[j][j+i-1],dp[j+1][j+i],std::min(height[j],height[j+i])*i);
            }
        }
    }
    return dp[0][size-1];
