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



-----------------------
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> vec(size, 0);
        std::vector<std::vector<int>> res(vec, size + 1);
    }
};
