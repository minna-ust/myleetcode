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
            //if ((i - (i >> 1) * 2) == 0) // 说明i是2的某次方 ---> 事实证明是错的, 比如i 为 6时;
            //if ( i & (i >> 1) == 0) //也不能说明i是2的某次方 ---> 比如i为5;
            // 为了判断一个正整数是不是 2 的整数次幂，可以利用方法一中提到的按位与运算的性质。正整数 y 是 2 的整数次幂，当且仅当 y&(y−1)=0。
            //     作者：LeetCode-Solution
            //     链接：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
            //     来源：力扣（LeetCode）
            //     著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
            if ((i & (i - 1)) == 0)
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
