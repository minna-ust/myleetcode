class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //注意nullptr检查!!!
        if (matrix == nullptr || str == nullptr || rows < 1 || cols < 1)
        {
            return false;
        }
        int strLength = strlen(str);
        if (strLength == 0)
        {
            return false;
        }

        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                int depth = 0;
                // return find(matrix, i, j, rows, cols, depth, str, strLength, visited);   //常见错误！！！
                if(find(matrix, i, j, rows, cols, depth, str, strLength, visited))
                {
                    return true;
                }
            }
        }
        delete[] visited;
        return false;
    }

    bool find(char* matrix, int i, int j, int rows, int cols, int depth, char* str, int strLength, bool *visited)
    {
        if (depth == strLength)
        {
            return true;
        }
        if ((matrix[i * cols + j] == str[depth]) && (visited[i * cols + j] == false) && (i >= 0) && (i < rows) && (j >= 0) && (j < cols))
        {
            visited[i * cols + j] = true;
            bool res = false;

            res =  find(matrix, i - 1, j, rows, cols, depth + 1, str, strLength, visited) ||
                   find(matrix, i, j - 1, rows, cols, depth + 1, str, strLength, visited) ||
                   find(matrix, i + 1, j, rows, cols, depth + 1, str, strLength, visited) ||
                   find(matrix, i, j + 1, rows, cols, depth + 1, str, strLength, visited);
            visited[i * cols + j] = false;
            return res;
        }
        else
        {
            return false;
        }
    }

};
