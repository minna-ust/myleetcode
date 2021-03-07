// input: 5 --->;
// 所有的i;
// [0, 1, 2, 3, 4, 5] ---> ;   (3 ---> 0011; 4 ---> 0100; 5 ---> 0101);
// 返回结果;
// [0, 1, 1, 2, 1, 2] ---> ;
// -----------------------;
// input: 8 ---> ;
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18] ---> ;
// [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2,  3,  2,  3,  3,  4,  1,  2,  2] ---> ;
// 13 ---> (8 + 5 ) ---> (1 + 2) ---> 3;
// -----------------------;
// 由上可以看出此问题可以用动态规划求解; 要填充的表格也就是要返回的结果;
// -----------------------;


#include <vector>
class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> res;
        if (num == 0)
        {
            res.push_back(0);
            return res;
        }
        if (num == 1)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        res.push_back(0);
        res.push_back(1);
        int base = 0;
        for (int i = 2; i <= num; ++i)
        {
            if ((i - (i >> 1) * 2) == 0) // 说明i是2的某次方
            {
                base = i;
                res.push_back(1);
                continue;
            }
            res.push_back(1 + res[i - base]);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    std::vector<int> res = Solution().countBits(7);
    return 0;
}
