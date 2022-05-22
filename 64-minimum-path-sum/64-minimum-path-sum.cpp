class Solution {
public:
    int minPathSum(vector<vector<int>> &ar)
{
    int m = ar.size();
    int n = ar[0].size();

    for (int j = n - 2; j >= 0; j--)
    {
        ar[m - 1][j] = ar[m - 1][j] + ar[m - 1][j + 1];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        ar[i][n - 1] = ar[i][n - 1] + ar[i + 1][n - 1];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            ar[i][j] = ar[i][j] + min(ar[i + 1][j], ar[i][j + 1]);
        }
    }
    return ar[0][0];
}
};