[-2,1,-3,4,-1,2,1];
-----------------------
|   |  0 |  1 |  2 | 3 |  4 | 5 | 6 |   |   |
|---+----+----+----+---+----+---+---+---+---|
| 1 | -2 |  1 | -3 | 4 | -1 | 2 | 1 |   |   |
| 2 | -1 | -2 |  1 | 3 |  1 | 3 |   |   |   |
| 3 | -4 |  2 |  0 | 5 |  2 |   |   |   |   |
| 4 |    |    |    |   |    |   |   |   |   |
| 5 |    |    |    |   |    |   |   |   |   |
| 6 |    |    |    |   |    |   |   |   |   |
| 7 |    |    |    |   |    |   |   |   |   |
|   |    |    |    |   |    |   |   |   |   |
|   |    |    |    |   |    |   |   |   |   |

       //当j = 0, i = 2时， sum = sums[i - 1][j] + nums[j + i - 1];

-----------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        std::vector<int> vec(size, 0);
        std::vector<std::vector<int>> sums(size + 1, vec);
        int maxSum = INT_MIN;
        for (int i = 1; i <= size; ++i)
        {
            for (int j = 0; j <= size - i; ++j)
            {
                // int sum = std::accumulate(nums.begin() + j, nums.begin() + j + i, 0);
                int sum = sums[i - 1][j] + nums[j + i - 1];
                sums[i][j] = sum;
                maxSum = std::max(maxSum, sum);
            }
        }
        return maxSum;
    }
};
