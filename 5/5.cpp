// baba
|   | 0 | 1 | 2 | 3 |
|---+---+---+---+---|
| 0 | 1 | 1 | 3 | 3 |
| 1 |   | 1 | 1 | 3 |
| 2 |   |   | 1 | 1 |
| 3 |   |   |   | 1 |
//先得到绿色的，再得到红色的，最后得到黄色的
      //用滑动窗口去理解这个过程，滑动窗口的尺寸由0,1,2递增到包含整个字符串，这将作为外层循环

string longestPalindrome(sring s)
{
    vector<int> v(s.size(), 0);
    vector<vector<int>> m(s.size(), v);

    vector<int> v1(2, 0);
    vector<vector<int>> v2(s.size(), v1);
    vector<vector<vector<int>>> idx(s.size(), v2);

    for (int k = 0; k < s.size(); ++k)
    {
        m[k][k] = 1;
        idx[k][k][0] = k;
        idx[k][k][1] = k;
    }
    for (int k = 0; k+1 < s.size(); ++k)
    {
        if (s[k] == s[k+1])
        {
            m[k][k+1] = 2;
            idx[k][k+1][0] = k;
            idx[k][k+1][1] = k+1;
        }
        else
        {
            m[k][k+1] = 1;
            idx[k][k+1][0] = k;
            idx[k][k+1][1] = k+1;
        }
    }

    for (int j = 2; j < s.size(); ++j)
    {
        for (int i = 0; i+j < s.size(); ++i)
        {
            if (s[i] == s[i+j])
            {
                m[i][i+j] = m[i+1][i+j-1] + 2;
                idx[i][i+j][0] = i;
                idx[i][i+j][1] = i+j;
            }
            else
            {
                if (m[i][i+j-1] > m[i+1][j])
                {
                    m[i][i+j] = m[i][i+j-1];
                    idx[i][i+j][0] = idx[i][i+j-1][0];
                    idx[i][i+j][1] = idx[i][i+j-1][1];
                }
                else
                {
                    m[i][i+j] = m[i+1][j];
                    idx[i][i+j][0] = idx[i+1][j][0];
                    idx[i][i+j][1] = idx[i+1][j][1];
                }
            }
        }
    }
    return s.substr(idx[0][s.size() - 1][0], idx[0][s.size() - 1][1] + 1);
}
