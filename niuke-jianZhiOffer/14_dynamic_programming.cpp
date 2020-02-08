class Solution {　　　　　　　　　　　　　//解题思路参考印象笔记
public:
    int cutRope(int number) {
        if (number < 2)
        {
            return 0;
        }
        if (number == 2) //按书本上的要求,　绳子不能不剪,　也就是只能剪成两半, 所以返回值为1
        {
            return 1;
        }
        
        int dp[number + 1][number + 1];
        for (int j = 1; j <= number; ++j)
        {
            dp[1][j] = j;
        }
        for (int i = 1; i <= number; ++i)
        {
            dp[i][i] = 1;
        }

        for (int i = 2; i <= number; ++i)
        {
            for (int j = i + 1; j <= number; ++j)
            {
                int value = 0;
                for (int k = 1; k <= (j - i); ++k)
                {
                    value = max(value, k * dp[i - 1][j - k]);
                }
                dp[i][j] = value;
            }
        }
        int result = 0;
        for (int i = 2; i <= number; ++i)
        {
            result = max(result, dp[i][number]);
        }
        return result;
    }
};
