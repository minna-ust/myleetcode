#include "stdcom.hpp"

class Solution
{
  public:
    void print1ToMaxOfNDigits(int n)
    {
        // assert(n > 0);
        if (n <= 0)
            return;
        char *arr = new char[n + 1];
        memset(arr, '0', n);
        arr[n] = '\0';

        recur(arr, 0, n);
        delete[] arr;
    }

    void recur(char *arr, int index, int n)
    {
        if (index >= n)
        {
            printf(" ");
            printNumber(arr);
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            arr[index] = '0' + i;
            recur(arr, index + 1, n);
        }
    }

    void printNumber(char *arr)
    {
        bool flag;
        while (*arr == '0')
        {
            arr++;
        }
        printf("%s", arr);
    }
};


int main(int *argc, char** argv)
{
    Solution().print1ToMaxOfNDigits(2);
    return 0;
}
