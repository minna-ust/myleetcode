class Solution {
public:
    int countOrders(int n) {
        if (n <= 0)
        {
            return 0;
        }
        int doubleN = 2 * n;
        long long int res = 1;
        int i = 1;
        bool flag = false;
        int mod = 1e9 + 7;
        while (i <= doubleN)
        {
            res *= i;
            if (flag)
            {
                res = res >> 1;
                flag = false;
            }
            else
                flag = true;
            res = res % mod;
            i++;
        }
        //res /= static_cast<int>(pow(2, n));
        return res % static_cast<int>(pow(10, 9) + 7);
    }
};
