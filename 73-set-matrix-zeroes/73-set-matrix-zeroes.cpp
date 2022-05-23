class Solution {
public:
    void setZeroes(vector<vector<int>> &v)
{
    int m = v.size();
    int n = v[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][j] = INT_MIN + 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == INT_MIN + 1)
            {
                // update row column  = 0;
                v[i][j] = 0;
                for (int k = 0; k < m; k++)
                {
                    if (v[k][j] != INT_MIN + 1)
                    {
                        v[k][j] = 0;
                    }
                }
                for (int k = 0; k < n; k++)
                {
                    if (v[i][k] != INT_MIN + 1)
                    {
                        v[i][k] = 0;
                    }
                }
            }
        }
    }
}
};