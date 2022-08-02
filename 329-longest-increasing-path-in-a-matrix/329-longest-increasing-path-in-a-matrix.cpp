class Solution {
public:
int helper(vector<vector<int>> &ar, int i, int j, int m, int n, vector<vector<int>> &output)
{
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return 0;
    }

    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    int right = j + 1 < n && ar[i][j + 1] > ar[i][j] ? helper(ar, i, j + 1, m, n, output) : 0;
    int left = j - 1 >= 0 && ar[i][j - 1] > ar[i][j] ? helper(ar, i, j - 1, m, n, output) : 0;
    int up = i - 1 >= 0 && ar[i - 1][j] > ar[i][j] ? helper(ar, i - 1, j, m, n, output) : 0;
    int down = i + 1 < m && ar[i + 1][j] > ar[i][j] ? helper(ar, i + 1, j, m, n, output) : 0;

    output[i][j] = max({left, right, up, down}) + 1;
    return output[i][j];
}

int longestIncreasingPath(vector<vector<int>> &ar)
{
    int m = ar.size();
    int n = ar[0].size();
    vector<vector<int>> output(m, vector<int>(n, -1));
    int res = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           int smallans = helper(ar, i, j, m, n, output);
           res = max(res, smallans);
        }
    }
    return res;
}

};