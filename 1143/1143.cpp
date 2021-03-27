                    bcde,ace;
                        |
                        |
                        |
                     bcd,ac
                     /      \
                    /       \
                   /         \
                 bc,ac     bcd,a
                   |         /
                  |         /
                  |        /
                 b,a     bc,a
                           /
                          /
                         /
                        b,a


                                 abcdcb, ccbe;
                            /                   \
                           /                     \
                          /                       \
                     abcdcb, ccb;             abcdc, ccbe;
                         |                       /      \
                         |                      /        \
                         |                     /          \
                     abcdc, cc;           abcd, ccbe;   abcdc, ccb;
                                                          /      \
                                                         /       \
                                                        /         \
                                                   abcd, ccb;    abcdc, cc;



|   |   | a | b | c | d | c | b |   |   |   |
|---+---+---+---+---+---+---+---+---+---+---|
|   | 0 | 0 | 0 | 0 | 0 | 0 | 0 |   |   |   |
| c | 0 | 0 | 0 | 1 | 1 | 1 | 1 |   |   |   |
| c | 0 | 0 | 0 | 1 | 1 | 2 | 2 |   |   |   |
| b | 0 |   |   |   |   |   |   |   |   |   |
| e | 0 |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |
|   |   |   |   |   |   |   |   |   |   |   |



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size() + 1;
        int cols = text2.size() + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int i = 1; i <= rows - 1; ++i)
        {
            for (int j = 1; j <= cols - 1; ++j)
            {
                if (text1[i - 1] == text2[j - 1]) //注意下标, 不是 text[i] == text[j]
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
};
