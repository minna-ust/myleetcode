class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0 || rows < 0 || cols < 0)
        {
            return 0;
        }

        bool *visited = new bool[rows * cols];
        for (int i = 0; i < rows * cols; ++i)
        {
            visited[i] = false;
        }

        int res = recurMove(threshold, 0, 0, rows, cols, visited);
        delete[] visited;
        return res;
    }

    int recurMove(int threshold, int i, int j, int rows, int cols, bool *visited)
    {
        if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
        {
            return 0;
        }
        visited[i * cols + j] = true;  //此处有逻辑问题,　执行此句代码后,　check的结果将永远是false!!!
        if (check(threshold, i, j, rows, cols, visited))
        {
            // visited[i * cols + j] = true;   //此句是有讲究的,　建议写完代码后,　细心检查一下逻辑问题!!!

            return 1 + recurMove(threshold, i - 1, j, rows, cols, visited) +
                       recurMove(threshold, i + 1, j, rows, cols, visited) +
                       recurMove(threshold, i, j - 1, rows, cols, visited) +
                       recurMove(threshold, i, j + 1, rows, cols, visited);
        }
        else
        {
            return 0;
        }
    }

    bool check(int threshold, int i, int j, int rows, int cols, bool *visited)
    {
        std::cout << "i: " << i << "j: " << j << std::endl;
        int sum = 0;
        sum += getDigitSum(i);
        sum += getDigitSum(j);
        if ((sum > threshold) || (i < 0) || (i >= rows) || (j < 0) || (j >= cols) || (visited[i * cols + j] == true))
        {
            return false;
        }
        return true;
    }

    int getDigitSum(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }
};
