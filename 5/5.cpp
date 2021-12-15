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
    for (int k = 0; k < s.size(); ++k)
    {
        m[k][k] = 1;
    }
    for (int k = 0; k < s.size(); ++k)
            {
                m[k][k+1] =

    for (int i : s.size())
    {
        for (int j = 0; j + i < s.size(); ++j)
        {
            for (int k = 0; k < s.size(); ++k)
            {
                m[j+k][j+k] =
}
