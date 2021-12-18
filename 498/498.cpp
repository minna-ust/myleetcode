vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    bool up = true;
    int i = 0;
    int j = 0;
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    while (!(i = m && j=n))
    {
        res.push_back(mat[i][j]);
        if (up)
        {
            i--;
            j++;
        }
        else
        {
            i++;
            j--;
        }
        if (i < 0 && j < n)
        {
            up = false;
            i++;
        }
        if (j < 0 && i < m)
        {
            up = true;
            j++;
        }
        if ( j >= n)
        {
            i+=2;j--;up=false;
        }
        if (i>=m)
        {
            j+=2;i--;up=true;
        }

    }
    return res;
}
